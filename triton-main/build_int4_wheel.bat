@echo off
setlocal EnableExtensions EnableDelayedExpansion

rem Optional overrides:
rem   PYTHON_EXE  Python used to build the wheel (default: python on PATH)
rem   HIP_PATH    HIP SDK root (default: C:\Program Files\AMD\ROCm\5.7)
rem   LLVM_SYSPATH pre-built LLVM directory (default: repo\build)
rem   MAX_JOBS    parallel build jobs (default: 4)

if not defined PYTHON_EXE set "PYTHON_EXE=python"
if not defined HIP_PATH set "HIP_PATH=C:\Program Files\AMD\ROCm\5.7"
if not defined LLVM_SYSPATH set "LLVM_SYSPATH=%~dp0..\build"
if not defined MAX_JOBS set "MAX_JOBS=4"

if not exist "%HIP_PATH%" (
    echo [ERROR] HIP SDK was not found at "%HIP_PATH%".
    echo         Set HIP_PATH before running this script.
    exit /b 1
)
if not exist "%LLVM_SYSPATH%\lib\cmake\llvm\LLVMConfig.cmake" (
    echo [ERROR] LLVMConfig.cmake was not found under "%LLVM_SYSPATH%".
    echo         Clone the complete repository or set LLVM_SYSPATH.
    exit /b 1
)

where cl.exe >nul 2>nul
if errorlevel 1 (
    set "VSWHERE=%ProgramFiles(x86)%\Microsoft Visual Studio\Installer\vswhere.exe"
    if not exist "!VSWHERE!" (
        echo [ERROR] cl.exe is not available and vswhere.exe was not found.
        echo         Install Visual Studio 2022 Build Tools with Desktop development with C++.
        exit /b 1
    )
    for /f "usebackq tokens=*" %%I in (`"!VSWHERE!" -latest -products * -requires Microsoft.VisualStudio.Component.VC.Tools.x86.x64 -property installationPath`) do set "VSROOT=%%I"
    if not defined VSROOT (
        echo [ERROR] Visual Studio C++ Build Tools were not found.
        exit /b 1
    )
    call "!VSROOT!\VC\Auxiliary\Build\vcvars64.bat"
    if errorlevel 1 exit /b 1
)

"%PYTHON_EXE%" -c "import sys" >nul 2>nul
if errorlevel 1 (
    echo [ERROR] Python could not be started: "%PYTHON_EXE%".
    echo         Set PYTHON_EXE to the target Python executable.
    exit /b 1
)
for /f "usebackq tokens=*" %%I in (`"%PYTHON_EXE%" -c "import sysconfig; print(sysconfig.get_path('scripts'))"`) do set "PATH=%%I;%PATH%"

where cmake.exe >nul 2>nul
if errorlevel 1 (
    echo [ERROR] cmake.exe is missing. Run: "%PYTHON_EXE%" -m pip install cmake ninja
    exit /b 1
)
where ninja.exe >nul 2>nul
if errorlevel 1 (
    echo [ERROR] ninja.exe is missing. Run: "%PYTHON_EXE%" -m pip install cmake ninja
    exit /b 1
)

set "CC=cl.exe"
set "CXX=cl.exe"
set "CMAKE_GENERATOR=Ninja"
set "TRITON_OFFLINE_BUILD=True"
set "TRITON_BUILD_PROTON=OFF"

echo [INFO] Python: %PYTHON_EXE%
echo [INFO] HIP_PATH: %HIP_PATH%
echo [INFO] LLVM_SYSPATH: %LLVM_SYSPATH%
echo [INFO] MAX_JOBS: %MAX_JOBS%

pushd "%~dp0"
if not exist dist mkdir dist
"%PYTHON_EXE%" -m pip wheel .\python --no-build-isolation --verbose --wheel-dir dist
set "RESULT=%ERRORLEVEL%"
popd
exit /b %RESULT%
