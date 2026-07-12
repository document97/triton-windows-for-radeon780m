# Building Triton for gfx1103 native INT4

Base Triton source: `b42b6f3` (Triton 3.3 lineage).

This tree contains the exact source edits used for the verified wheel. The
important changes are:

1. Expose `get_int4_ty` through the Python IR builder.
2. Add `tl.int4` and `tl.uint4` to the language, JIT type canonicalization and
   interpreter mappings.
3. Permit signed/unsigned 4-bit operands in `tl.dot` with `int32`
   accumulation.
4. Extend AMD `AccelerateAMDMatmul` applicability to `{i4, i4, i32, i32}` so
   Triton lowers `tl.dot(int4, int4)` to
   `v_wmma_i32_16x16x16_iu4` on RDNA3 gfx11.

## Requirements

* Windows x64, Visual Studio C++ build tools, CMake and Ninja.
* Python 3.12 matching the target ComfyUI embedded Python.
* HIP SDK 5.7 installed at `C:\Program Files\AMD\ROCm\5.7`.
* A configured LLVM/MLIR build tree. It is deliberately not committed because
  it is over 1 GiB. Set `LLVM_SYSPATH` to that build directory.

## Build

Edit the machine-specific paths near the top of `build_int4_wheel.bat`:

* Visual Studio `vcvars64.bat`
* CMake/Python Scripts path
* `LLVM_SYSPATH`
* `HIP_PATH`
* target embedded Python executable

Then run:

```bat
build_int4_wheel.bat
```

The wheel is written to `dist\triton-3.3.0-cp312-cp312-win_amd64.whl`.
`continue_triton_build.bat` is only useful after a local `python\build` tree
exists; that build tree is ignored by Git.

## Smoke test

Use a kernel with `tl.dot(a_i4, b_i4, out_dtype=tl.int32)` and verify generated
AMDGPU assembly contains `v_wmma_i32_16x16x16_iu4`. The frontend types alone
are insufficient: the AMD matmul pass change is what selects the native WMMA
instruction.

