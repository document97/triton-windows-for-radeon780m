# Native INT4 Triton for Radeon 780M on Windows

This repository combines a pre-built LLVM/MLIR tree with a patched Triton
3.3 source tree for native W4A4 kernels on the Radeon 780M (`gfx1103`) under
Windows, HIP SDK and ZLUDA.

The patch adds first-class `tl.int4` and `tl.uint4`, permits INT4 operands in
`tl.dot` with INT32 accumulation, and extends AMD's
`AccelerateAMDMatmul` pass for `{i4, i4, i32, i32}`. On RDNA3, a compatible
kernel lowers to:

```text
v_wmma_i32_16x16x16_iu4
```

This is native IU4 WMMA arithmetic, not an eager or INT8 fallback.

## Support scope

- Primary target: Radeon 780M / `gfx1103`.
- Host: Windows x64.
- Compiler/runtime combination tested: Triton 3.3, LLVM/MLIR commit
  `71a977d0`, HIP SDK 5.7, ZLUDA and PyTorch 2.7.1+cu118.
- Main use case: the companion ComfyUI W4A4 ConvRot backend.

Other gfx11 GPUs or software versions may work, but have not been verified by
this project.

## Prerequisites

### Required to build the wheel

- Visual Studio 2022 or newer with **Desktop development with C++**.
- Python matching the environment where the wheel will be installed. Python
  3.12 is the tested version.
- CMake and Ninja installed into that Python environment:

  ```powershell
  python -m pip install cmake ninja
  ```

- HIP SDK 5.7 (the tested path is `C:\Program Files\AMD\ROCm\5.7`).
- The LLVM source tree at commit `71a977d0` for source headers.
- At least 32 GB system RAM is recommended. Peak memory usage during the
  tested build was approximately 26 GB.
- The clone contains about 1.5 GB of pre-built libraries. Keep additional
  disk space for LLVM sources, temporary build files and the wheel.

### Required at runtime

- A ZLUDA-enabled PyTorch environment that exposes the AMD GPU as
  `torch.cuda` while Triton reports a HIP `gfx1103` target.
- For ComfyUI integration, a ComfyUI/dev + comfy-kitchen version with W4A4
  ConvRot support and a compatible INT4 backend plugin.

The exact PyTorch, ZLUDA and ComfyUI versions above are tested versions, not
universal hard requirements.

## Repository layout

```text
triton-windows-for-radeon780m/
|-- build/                    pre-built LLVM/MLIR libraries and CMake files
|-- llvm-project/             LLVM source commit 71a977d0 (download separately)
|-- triton-main/              patched Triton source
|-- tests/smoke_test_int4.py  native IU4 WMMA verification
`-- patch_cmake_paths.ps1     relocates generated LLVM CMake paths
```

Do not delete `build/`: it is the pre-built LLVM/MLIR tree used to build the
Triton wheel. The `llvm-project/` directory is not included and must be
downloaded separately.

## Build the wheel

1. Clone this repository:

   ```powershell
   git clone --depth=1 https://github.com/document97/triton-windows-for-radeon780m.git
   cd triton-windows-for-radeon780m
   ```

2. Download the matching LLVM source and check out the required commit:

   ```powershell
   git clone --depth=1 --filter=blob:none --no-checkout https://github.com/llvm/llvm-project.git llvm-project
   git -C llvm-project fetch --depth=1 origin 71a977d0d611f3e9f6137a6b8a26b730b2886ce9
   git -C llvm-project checkout FETCH_HEAD
   ```

3. Relocate the generated LLVM/MLIR CMake files:

   ```powershell
   powershell.exe -NoProfile -ExecutionPolicy Bypass -File .\patch_cmake_paths.ps1 -LlvmSourcePath .\llvm-project
   ```

   A source tree stored elsewhere is also supported:

   ```powershell
   powershell.exe -NoProfile -ExecutionPolicy Bypass -File .\patch_cmake_paths.ps1 -LlvmSourcePath C:\src\llvm-project
   ```

4. Select the target Python and build the wheel:

   ```powershell
   $env:PYTHON_EXE = "D:\ComfyUI-aki-v2\python\python.exe"
   $env:HIP_PATH = "C:\Program Files\AMD\ROCm\5.7"
   $env:MAX_JOBS = "4"
   .\triton-main\build_int4_wheel.bat
   ```

   `build_int4_wheel.bat` automatically finds Visual Studio through
   `vswhere.exe`, uses the repository's `build/` directory, and writes the
   wheel to `triton-main\dist\`. Optional overrides are `PYTHON_EXE`,
   `HIP_PATH`, `LLVM_SYSPATH` and `MAX_JOBS`.

## Install into ComfyUI

Install the generated wheel with the same Python executable used by ComfyUI:

```powershell
$wheel = Get-ChildItem .\triton-main\dist\triton-*.whl |
    Sort-Object LastWriteTime -Descending |
    Select-Object -First 1
& D:\ComfyUI-aki-v2\python\python.exe -m pip install --force-reinstall $wheel.FullName
```

Confirm that Python imports the intended package rather than another Triton
installation:

```powershell
D:\ComfyUI-aki-v2\python\python.exe -c "import triton; print(triton.__version__); print(triton.__file__)"
```

## Verify native INT4

Run the smoke test inside the ZLUDA-enabled environment:

```powershell
D:\ComfyUI-aki-v2\python\python.exe .\tests\smoke_test_int4.py
```

Expected output includes:

```text
[OK] tl.int4 available
[OK] tl.uint4 available
[INFO] Triton target: GPUTarget(backend='hip', arch='gfx1103', warp_size=32)
[OK] found v_wmma_i32_16x16x16_iu4
```

Checking the frontend types alone is insufficient. The final line proves that
the test kernel reached the native IU4 WMMA instruction in generated AMDGPU
assembly.

## Troubleshooting

- **`cl.exe` or Visual Studio is not found:** install the Desktop development
  with C++ workload. The build script uses `vswhere.exe` to load `vcvars64.bat`.
- **`cmake.exe` or `ninja.exe` is not found:** install both with the same
  `PYTHON_EXE` used for the build.
- **CMake files still reference `C:\Users\Glimmer`:** rerun
  `patch_cmake_paths.ps1` with the correct `-LlvmSourcePath`.
- **PowerShell refuses to run the patch script:** use the documented
  `-ExecutionPolicy Bypass` command; it applies only to that process.
- **HIP SDK is not found:** set `HIP_PATH` before running the build script.
- **MinGW is selected instead of MSVC:** remove MinGW from the current `PATH`
  for the build. The script explicitly sets `CC=cl.exe` and `CXX=cl.exe`.
- **The wheel installs but the smoke test has no `tl.int4`:** inspect
  `triton.__file__`; another Triton package is being imported.
- **The target is CUDA instead of HIP:** the test was not started through the
  working ZLUDA/HIP Triton environment.
- **`v_wmma_i32_16x16x16_iu4` is missing:** the compiler patch is absent, the
  target is not compatible gfx11, or a different Triton installation was used.

## Build details

| Item | Value |
|---|---|
| Triton base | `b42b6f3` (Triton 3.3 lineage) |
| LLVM commit | `71a977d0d611f3e9f6137a6b8a26b730b2886ce9` |
| LLVM projects | `mlir;llvm` |
| LLVM targets | `host;NVPTX;AMDGPU` |
| Assertions | enabled |
| Tested compiler | MSVC 19.51 (Visual Studio 2026) |
| Pre-built static libraries | 499 `.lib` files, approximately 1.3 GB |

## Test environment

- AMD Ryzen 7 8845H with Radeon 780M (`gfx1103`)
- 32 GB LPDDR5-6400
- Python 3.12
- PyTorch 2.7.1+cu118 + ZLUDA 3.9.6 + HIP SDK 5.7
- ComfyUI dev branch with matching comfy-kitchen ConvRot support

## Known limitations

- The pre-built LLVM libraries use the MSVC ABI and are Windows x64 specific.
- The current binary and kernel validation target is `gfx1103`.
- The supplied build was validated with Python 3.12; a different Python ABI
  requires a wheel built with that Python executable.
- The project does not install or configure ZLUDA, PyTorch, ComfyUI or the
  companion INT4 plugin automatically.

## Thanks

- [lshqqytiger](https://github.com/lshqqytiger) for maintaining the
  [Windows Triton fork](https://github.com/lshqqytiger/triton) and ZLUDA work
  for AMD hardware on Windows.
- [likelovewant](https://github.com/likelovewant) for Radeon consumer-GPU
  patches, build configurations and ROCm library support.
- [viralvfx/ComfyUI-INT4-Fast](https://github.com/viralvfx/ComfyUI-INT4-Fast)
  for the W4A4/ConvRot layout, quantized checkpoint handling and ComfyUI
  runtime integration foundation used by the companion plugin. The gfx1103
  Triton compiler and native IU4 WMMA changes in this repository extend that
  foundation.
- The LLVM, MLIR, Triton, ZLUDA, PyTorch and ComfyUI communities.

## License

The Triton source tree retains its upstream license in
[`triton-main/LICENSE`](triton-main/LICENSE). LLVM/MLIR and other bundled
components remain subject to their respective upstream licenses.
