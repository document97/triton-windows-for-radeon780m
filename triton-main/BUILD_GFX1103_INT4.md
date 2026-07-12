# Building Triton for gfx1103 native INT4

Base Triton source: `b42b6f3` (Triton 3.3 lineage).

This tree contains the source edits used for the verified Radeon 780M wheel:

1. Expose `get_int4_ty` through the Python IR builder.
2. Add `tl.int4` and `tl.uint4` to the language, JIT type canonicalization and
   interpreter mappings.
3. Permit signed/unsigned 4-bit operands in `tl.dot` with INT32 accumulation.
4. Extend AMD `AccelerateAMDMatmul` applicability to `{i4, i4, i32, i32}` so
   Triton lowers a compatible INT4 dot to
   `v_wmma_i32_16x16x16_iu4` on RDNA3 gfx11.

The repository root contains the pre-built LLVM/MLIR tree, relocatable build
script, prerequisites, installation instructions and troubleshooting guide.
Follow [`../README.md`](../README.md) to build and install the wheel.

After installation, run:

```powershell
python ..\tests\smoke_test_int4.py
```

The test must find `v_wmma_i32_16x16x16_iu4` in generated AMDGPU assembly.
The presence of the frontend INT4 types alone does not prove native execution.
