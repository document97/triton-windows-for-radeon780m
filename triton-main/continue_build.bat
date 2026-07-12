@echo off
call "C:\Program Files\Microsoft Visual Studio\18\Community\VC\Auxiliary\Build\vcvars64.bat"
set LLVM_SYSPATH=C:\Users\Glimmer\Documents\llvm-project-71a977d0d611f3e9f6137a6b8a26b730b2886ce9\build
cd /d C:\Users\Glimmer\Documents\triton-lshq\triton-main_old\python\build\cmake.win-amd64-cpython-3.12
echo [BUILD] Starting cmake --build... (this will take 10-20 mins)
echo [BUILD] Config: TritonRelBuildWithAsserts
cmake --build . --config TritonRelBuildWithAsserts
echo [BUILD] cmake --build exit code: %ERRORLEVEL%
if %ERRORLEVEL% equ 0 (
    echo [BUILD] C++ compilation successful!
) else (
    echo [BUILD] C++ compilation had errors. Check the output above.
)
pause
