"""Compile a native W4A4 dot kernel and verify the generated gfx11 assembly."""

import sys

import torch
import triton
import triton.language as tl


INSTRUCTION = "v_wmma_i32_16x16x16_iu4"


@triton.jit
def _int4_dot_kernel(a_ptr, b_ptr, out_ptr, BLOCK: tl.constexpr):
    rows = tl.arange(0, BLOCK)
    packed_k = tl.arange(0, BLOCK // 2)

    a_bytes = tl.load(a_ptr + rows[:, None] * (BLOCK // 2) + packed_k[None, :])
    b_bytes = tl.load(b_ptr + rows[:, None] * (BLOCK // 2) + packed_k[None, :])
    a_i4 = tl.reshape(
        tl.join((a_bytes & 0xF).to(tl.int4), (a_bytes >> 4).to(tl.int4)),
        (BLOCK, BLOCK),
    )
    b_i4 = tl.reshape(
        tl.join((b_bytes & 0xF).to(tl.int4), (b_bytes >> 4).to(tl.int4)),
        (BLOCK, BLOCK),
    )
    result = tl.dot(a_i4, tl.trans(b_i4), out_dtype=tl.int32)
    tl.store(out_ptr + rows[:, None] * BLOCK + rows[None, :], result)


def fail(message: str) -> None:
    print(f"[FAIL] {message}", file=sys.stderr)
    raise SystemExit(1)


def main() -> None:
    if not hasattr(tl, "int4"):
        fail("tl.int4 is unavailable; this is not the patched Triton build")
    print("[OK] tl.int4 available")

    if not hasattr(tl, "uint4"):
        fail("tl.uint4 is unavailable; this is not the patched Triton build")
    print("[OK] tl.uint4 available")

    if not torch.cuda.is_available():
        fail("torch.cuda is unavailable; start this test in the ZLUDA-enabled environment")

    target = triton.runtime.driver.active.get_current_target()
    print(f"[INFO] Triton target: {target}")
    if target.backend != "hip" or not str(target.arch).startswith("gfx11"):
        fail(f"expected a HIP gfx11 target, got {target}")

    block = 64
    a = torch.zeros((block, block // 2), dtype=torch.uint8, device="cuda")
    b = torch.zeros_like(a)
    out = torch.empty((block, block), dtype=torch.int32, device="cuda")
    compiled = _int4_dot_kernel.warmup(
        a,
        b,
        out,
        BLOCK=block,
        grid=(1,),
        num_warps=8,
    )

    amdgcn = compiled.asm.get("amdgcn", "")
    if INSTRUCTION not in amdgcn:
        fail(f"{INSTRUCTION} was not found in generated AMDGPU assembly")
    print(f"[OK] found {INSTRUCTION}")


if __name__ == "__main__":
    main()
