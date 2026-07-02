
# Pre-built LLVM with MLIR + AMDGPU for Triton on Windows

This repo contains a pre-built LLVM + MLIR (commit `71a977d0`) compiled with:
- MLIR enabled
- NVPTX + AMDGPU + X86 targets
- Assertions enabled
- MSVC 2026 (19.51), Release mode

## Purpose

Needed to compile [triton](https://github.com/lshqqytiger/triton) from source on Windows for AMD GPUs (780M) via ZLUDA.

## Usage

1. **Clone this repo**:
   ```
   git clone --depth=1 https://github.com/document97/triton-windows-for780m.git
   ```

2. **Run path patching** (cmake configs have hardcoded paths):
   ```powershell
   .\patch_cmake_paths.ps1
   ```

3. **Set up environment**:
   ```cmd
   call "C:\Program Files\Microsoft Visual Studio\2022\Community\VC\Auxiliary\Build\vcvars64.bat"
   set CMAKE_GENERATOR=Ninja
   set LLVM_SYSPATH=C:\path\to\triton-windows-for780m\build
   ```

4. **Build Triton wheel**:
   ```cmd
   cd triton-main\python
   pip install . --no-build-isolation --verbose
   ```
   Or generate a `.whl`:
   ```cmd
   pip wheel . --no-build-isolation --verbose
   ```

## Notes

- MSVC 2022+ required (the .lib files use the MSVC ABI).
- Install `ninja` and `cmake` via `pip install cmake ninja`.
- First clone is ~1.5 GB due to compiled static libraries.
- For the LLVM source headers, download [llvm-project](https://github.com/llvm/llvm-project) at commit `71a977d0` — the cmake configs reference source tree include paths.

## Build details

| Item | Value |
|------|-------|
| LLVM commit | 71a977d0d611f3e9f6137a6b8a26b730b2886ce9 |
| CMake | `-DLLVM_ENABLE_PROJECTS=mlir;llvm -DLLVM_TARGETS_TO_BUILD=host;NVPTX;AMDGPU -DLLVM_ENABLE_ASSERTIONS=ON` |
| Compiler | MSVC 19.51 (VS 2026) |
| Static libs | 499 .lib files, ~1.3 GB |

