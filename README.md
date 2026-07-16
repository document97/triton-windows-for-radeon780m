# Native INT4 Triton for Radeon 780M on Windows

This repository provides a Windows x64 build of Triton 3.3 with native INT4
support for the Radeon 780M (`gfx1103`). It includes the Triton source tree,
the AMD backend, a relocatable pre-built LLVM/MLIR toolchain, and a build
script that creates a wheel for a selected Python interpreter.

The compiler exposes `tl.int4` and `tl.uint4`, accepts INT4 operands in
`tl.dot` with INT32 accumulation, and lowers compatible gfx11 W4A4 kernels to
the native AMD instruction:

```text
v_wmma_i32_16x16x16_iu4
```

## Repository contents

- `triton-main/`: Triton 3.3 source with the AMD backend and native INT4
  compiler support.
- `build/`: pre-built LLVM/MLIR headers, CMake configuration, tools, and
  static libraries required by the offline Triton build.
- `triton-main/build_int4_wheel.bat`: Windows wheel build entry point.
- `tests/smoke_test_int4.py`: compiles a W4A4 kernel and checks its generated
  AMDGPU assembly for native IU4 WMMA.

The bundled LLVM/MLIR tree is already configured for this repository and does
not require a separate LLVM checkout.

## Target environment

| Component | Supported or tested configuration |
|---|---|
| Host | Windows x64 |
| GPU | Radeon 780M (`gfx1103`) |
| Triton | 3.3 lineage, base commit `b42b6f3` |
| LLVM/MLIR | `71a977d0d611f3e9f6137a6b8a26b730b2886ce9` |
| HIP SDK | 5.7 |
| Runtime bridge | ZLUDA |
| Tested PyTorch runtime | 2.7.1+cu118 |

The wheel is specific to the Python ABI used for the build. Build it with the
same Python installation that will load it, or with another interpreter that
has the identical major/minor version and architecture.

## Prerequisites

- Visual Studio 2022 or newer with the **Desktop development with C++**
  workload and x64 MSVC tools.
- A 64-bit Python interpreter for the target environment.
- HIP SDK 5.7. The default location used by the script is
  `C:\Program Files\AMD\ROCm\5.7`.
- Enough disk space for the repository, temporary build files, and the wheel.
  The tracked pre-built toolchain is approximately 1.5 GB.
- At least 16 GB of system memory is recommended.

Install the Python-side build dependencies into the target interpreter:

```powershell
$python = "C:\path\to\target\python.exe"
& $python -m pip install --upgrade setuptools wheel cmake ninja pybind11 packaging
```

## Build the wheel

Clone the complete repository and run the build script from its root:

```powershell
git clone https://github.com/document97/triton-windows-for-radeon780m.git
cd triton-windows-for-radeon780m

$python = "C:\path\to\target\python.exe"
$env:PYTHON_EXE = $python
.\triton-main\build_int4_wheel.bat
```

The script locates Visual Studio through `vswhere.exe`, selects MSVC and
Ninja, uses the bundled `build/` LLVM/MLIR tree, and performs an offline
Triton build. The wheel is written to:

```text
triton-main\dist\triton-3.3.0+git<commit>-cp<abi>-cp<abi>-win_amd64.whl
```

The `cp<abi>` tag comes from `PYTHON_EXE`. Rebuild the wheel for each Python
major/minor ABI instead of renaming an existing wheel.

### Build settings

The build script accepts these optional environment variables:

| Variable | Default | Purpose |
|---|---|---|
| `PYTHON_EXE` | `python` on `PATH` | Python interpreter and wheel ABI |
| `HIP_PATH` | `C:\Program Files\AMD\ROCm\5.7` | HIP SDK root |
| `LLVM_SYSPATH` | repository `build/` directory | Pre-built LLVM/MLIR root |
| `MAX_JOBS` | `4` | Maximum parallel compile jobs |

For example, set a non-default HIP installation before starting the build:

```powershell
$env:HIP_PATH = "C:\path\to\AMD\ROCm"
.\triton-main\build_int4_wheel.bat
```

## Install the wheel

Install the generated wheel into the same target environment without pulling
another Triton dependency:

```powershell
& $python -m pip install --force-reinstall --no-deps "C:\path\to\triton-wheel.whl"
```

Confirm that Python imports the intended installation:

```powershell
& $python -c "import triton; print(triton.__file__)"
```

## Verify native INT4

Run the smoke test from a working ZLUDA environment in which the Radeon GPU is
available through `torch.cuda` and Triton reports a HIP gfx11 target:

```powershell
& $python .\tests\smoke_test_int4.py
```

Expected output includes:

```text
[OK] tl.int4 available
[OK] tl.uint4 available
[INFO] Triton target: GPUTarget(backend='hip', arch='gfx1103', warp_size=32)
[OK] found v_wmma_i32_16x16x16_iu4
```

The final line verifies native IU4 WMMA in the generated AMDGPU assembly.
Checking only the Python types does not prove that the kernel reached the
native instruction.

## Troubleshooting

- **Visual Studio or `cl.exe` is not found:** install the Desktop development
  with C++ workload. The script uses `vswhere.exe` to load the x64 developer
  environment automatically.
- **`cmake.exe` or `ninja.exe` is not found:** install the build dependencies
  with the same interpreter assigned to `PYTHON_EXE`.
- **The HIP SDK is not found:** set `HIP_PATH` to the SDK root before running
  the build script.
- **`LLVMConfig.cmake` is not found:** use a complete clone containing the
  tracked `build/` directory, or point `LLVM_SYSPATH` at a compatible
  pre-built LLVM/MLIR tree.
- **The wheel is rejected as incompatible:** its `cp<abi>` tag does not match
  the target Python version or architecture. Rebuild it with that Python.
- **The installed package has no `tl.int4`:** check `triton.__file__`; another
  Triton installation is being imported first.
- **The smoke-test target is CUDA instead of HIP:** start it through the
  working ZLUDA environment. A regular CUDA PyTorch environment cannot perform
  the AMD native-instruction check.
- **The IU4 instruction is absent:** confirm that the active target is HIP
  `gfx1103` or another compatible gfx11 target and that the wheel came from
  this repository.

## Build details

| Item | Value |
|---|---|
| LLVM projects | `mlir;llvm` |
| LLVM targets | `host;NVPTX;AMDGPU` |
| LLVM assertions | enabled |
| Build generator | Ninja |
| Host compiler | MSVC |
| Bundled static libraries | 499 `.lib` files, approximately 1.3 GB |

## Acknowledgements

- [lshqqytiger](https://github.com/lshqqytiger) for the Windows Triton fork
  and ZLUDA work for AMD hardware on Windows.
- [likelovewant](https://github.com/likelovewant) for Radeon consumer-GPU
  patches, build configurations, and ROCm library support.
- [viralvfx/ComfyUI-INT4-Fast](https://github.com/viralvfx/ComfyUI-INT4-Fast)
  for the W4A4/ConvRot runtime integration foundation.
- The LLVM, MLIR, Triton, ZLUDA, PyTorch, and ComfyUI projects and
  communities.

## License

The Triton source tree retains its upstream license in
[`triton-main/LICENSE`](triton-main/LICENSE). LLVM/MLIR and other bundled
components remain subject to their respective upstream licenses.
