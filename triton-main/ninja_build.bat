@echo off
cd /d "C:\Users\Glimmer\Documents\triton-lshq\triton-main_old\python\build\cmake.win-amd64-cpython-3.12"
echo === Looking for build error ===
dir *.log 2>nul
echo === Run ninja build ===
ninja 2>&1
echo NINJA_EXIT=%ERRORLEVEL%
pause
