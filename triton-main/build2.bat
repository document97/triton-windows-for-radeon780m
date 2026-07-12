@echo off
call "C:\Program Files\Microsoft Visual Studio\18\Community\VC\Auxiliary\Build\vcvars64.bat" > nul
echo INCLUDE from cmd:
echo [%INCLUDE%]
echo.
echo Checking Python sees INCLUDE:
D:\ComfyUI-aki-v2\python\python.exe -c "import os; inc=os.environ.get('INCLUDE','NOT_FOUND'); print('INCLUDE length:', len(inc)); print('First 100 chars:', inc[:100])"
echo.
cd /d "C:\Users\Glimmer\Documents\triton-lshq\triton-main_old"
set LLVM_SYSPATH=C:\Users\Glimmer\Documents\llvm-project-71a977d0d611f3e9f6137a6b8a26b730b2886ce9\build
set CMAKE_GENERATOR=Ninja
echo Running build...
D:\ComfyUI-aki-v2\python\python.exe -m pip install ./python/ --verbose --no-build-isolation 2>&1 | findstr /V "??: ????"
echo EXIT_CODE=%ERRORLEVEL%
pause
