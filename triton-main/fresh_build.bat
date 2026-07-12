@echo off
call "C:\Program Files\Microsoft Visual Studio\18\Community\VC\Auxiliary\Build\vcvars64.bat"
set LLVM_SYSPATH=C:\Users\Glimmer\Documents\llvm-project-71a977d0d611f3e9f6137a6b8a26b730b2886ce9\build
set CMAKE_GENERATOR=Ninja
cd /d C:\Users\Glimmer\Documents\triton-lshq\triton-main_old
echo [BUILD] Fresh rebuild with RUNTIME_OUTPUT_DIRECTORY fix...
D:\ComfyUI-aki-v2\python\python.exe -m pip wheel ./python/ --no-build-isolation --verbose
echo [BUILD] pip wheel exit code: %ERRORLEVEL%
if %ERRORLEVEL% equ 0 (
    echo [BUILD] Wheel built successfully!
) else (
    echo [BUILD] Wheel build failed.
)
pause
