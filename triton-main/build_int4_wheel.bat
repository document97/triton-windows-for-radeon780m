@echo off
setlocal

call "C:\Program Files\Microsoft Visual Studio\18\Community\VC\Auxiliary\Build\vcvars64.bat"
if errorlevel 1 exit /b 1

set "PATH=C:\Users\Glimmer\AppData\Local\Programs\Python\Python312\Lib\site-packages\cmake\data\bin;D:\ComfyUI-aki-v2\python\Scripts;%PATH%"
set "PATH=%PATH:E:\mingw64\bin;=%"
set "CC=cl.exe"
set "CXX=cl.exe"
set "CMAKE_GENERATOR=Ninja"
rem The document97 repository stores the prebuilt LLVM tree next to triton-main.
set "LLVM_SYSPATH=%~dp0..\build"
set "HIP_PATH=C:\Program Files\AMD\ROCm\5.7"
set "TRITON_OFFLINE_BUILD=True"
set "TRITON_BUILD_PROTON=OFF"
set "MAX_JOBS=4"

where cmake.exe
where ninja.exe
where cl.exe
cmake --version

if not exist dist mkdir dist
D:\ComfyUI-aki-v2\python\python.exe -m pip wheel .\python\ --no-build-isolation --verbose --wheel-dir dist
exit /b %ERRORLEVEL%
