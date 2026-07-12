@echo off
echo === MSVC Environment ===
call "C:\Program Files\Microsoft Visual Studio\18\Community\VC\Auxiliary\Build\vcvars64.bat"
echo === Build TRITON ===
cd /d "C:\Users\Glimmer\Documents\triton-lshq\triton-main_old"
set LLVM_SYSPATH=C:\Users\Glimmer\Documents\llvm-project-71a977d0d611f3e9f6137a6b8a26b730b2886ce9\build
set CMAKE_GENERATOR=Ninja
echo === Starting pip install ===
pip install ./python/ --verbose --no-build-isolation
echo EXIT_CODE=%ERRORLEVEL%
echo === BUILD COMPLETE ===
pause
