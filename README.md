
# Pre-built LLVM + Triton native INT4 for Radeon 780M on Windows

This repo contains a pre-built LLVM + MLIR (commit `71a977d0`) compiled with:
- MLIR enabled
- NVPTX + AMDGPU + X86 targets
- Assertions enabled
- MSVC 2026 (19.51), Release mode

## Purpose

Needed to compile [Triton](https://github.com/lshqqytiger/triton) from source on Windows for AMD GPUs (Radeon 780M / `gfx1103`) via ZLUDA. The repository keeps the pre-built LLVM/MLIR tree in `build/` and the matching Triton source in `triton-main/`.

## Native INT4 update

The `triton-main` directory includes the native W4A4 compiler changes used by
the ComfyUI INT4 ConvRot backend:

- first-class `tl.int4` and `tl.uint4` frontend and IR types;
- signed/unsigned INT4 operands for `tl.dot` with INT32 accumulation;
- AMD `AccelerateAMDMatmul` support for `{i4, i4, i32, i32}`;
- lowering to the native RDNA3 instruction
  `v_wmma_i32_16x16x16_iu4` on `gfx1103`.

The resulting wheel was verified with PyTorch 2.7.1+cu118, ZLUDA, HIP SDK
5.7 and Radeon 780M. This is native IU4 WMMA arithmetic; it is not an eager
or INT8 arithmetic fallback.

## Usage

1. **Clone this repo**:
   ```
   git clone --depth=1 https://github.com/document97/triton-windows-for-radeon780m.git
   ```

2. **Run path patching** (cmake configs have hardcoded paths):
   ```powershell
   .\patch_cmake_paths.ps1
   ```

3. **Set up environment**:
   ```cmd
   call "C:\Program Files\Microsoft Visual Studio\2026\Community\VC\Auxiliary\Build\vcvars64.bat"
   set CMAKE_GENERATOR=Ninja
   set LLVM_SYSPATH=C:\path\to\triton-windows-for-radeon780m\build
   ```

4. **Build Triton wheel**:
   ```cmd
   cd triton-main\python
   pip install . --no-build-isolation --verbose
   ```
   Or generate a `.whl`:
   ```cmd
   pip wheel . --no-build-isolation --verbose --wheel-dir ..\dist
   ```

## Notes

- MSVC 2022+ required (the .lib files use the MSVC ABI).
- Install `ninja` and `cmake` via `pip install cmake ninja`.
- First clone is ~1.5 GB due to compiled static libraries.
- For the LLVM source headers, download [llvm-project](https://github.com/llvm/llvm-project) at commit `71a977d0` — the cmake configs reference source tree include paths.
- Maximum memory use can reach 26GB in the building process, testing on HIP SDK 5.7.1, using patches from likelovewant's repo.
- `triton-main\build_int4_wheel.bat` already points `LLVM_SYSPATH` to the
  repository's sibling `build` directory. Update only the Visual Studio,
  Python and HIP paths if they differ on your machine.
- After installation, a smoke test should report Triton `int4`/`uint4` types
  and generated AMDGPU assembly containing `v_wmma_i32_16x16x16_iu4`.
- Errors may contained in README.md and the code. Sorry, this is just my first open-source project.

## Build details

| Item | Value |
|------|-------|
| LLVM commit | 71a977d0d611f3e9f6137a6b8a26b730b2886ce9 |
| CMake | `-DLLVM_ENABLE_PROJECTS=mlir;llvm -DLLVM_TARGETS_TO_BUILD=host;NVPTX;AMDGPU -DLLVM_ENABLE_ASSERTIONS=ON` |
| Compiler | MSVC 19.51 (VS 2026) |
| Static libs | 499 .lib files, ~1.3 GB |

## Testing Environments
- AMD Ryzen7 8845H w/ Radeon(TM) 780M Graphics
- 32 GB LPDDR5 6400MT/s
- Torch 2.7.1+cu118 + ZLUDA 3.9.6 + HIP SDK 5.7
- Newest ComfyUI version from master branch.

## Thanks

This project relies heavily on the foundational work and tools provided by the open-source community. Special thanks to:

- **[lshqqytiger](https://github.com/lshqqytiger)**: For maintaining the [Triton Windows fork](https://github.com/lshqqytiger/triton) and adapting ZLUDA for AMD platforms on Windows.
- **[likelovewant](https://github.com/likelovewant)**: For providing valuable patches, build configurations, and ROCm library support tailored for the AMD Radeon 780M APU (gfx1103) and other consumer AMD hardware.
- **[viralvfx/ComfyUI-INT4-Fast](https://github.com/viralvfx/ComfyUI-INT4-Fast)**: For the ComfyUI INT4 implementation that provided the W4A4/ConvRot layout, quantized checkpoint handling, and runtime integration foundation used by the companion plugin. The gfx1103-native Triton compiler and IU4 WMMA work in this repository extends that foundation.
- **The LLVM & MLIR Developers**: For building and maintaining the foundational compiler infrastructure.
- **The Triton and ZLUDA Communities**: For making high-performance CUDA-compatible kernels accessible on AMD hardware.
- **The PyTorch and ComfyUI Communities**: For driving the development of local AI pipelines and broadening hardware compatibility.
