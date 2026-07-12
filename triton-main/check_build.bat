@echo off
cd /d "C:\Users\Glimmer\Documents\triton-lshq\triton-main_old\python\build\cmake.win-amd64-cpython-3.12"
echo === Ninja targets remaining ===
ninja -n 2>&1 | find /V "ninja: no work to do" | find /V "ninja: Build" | head -20
echo === Try ninja build and capture error ===
ninja 2>&1 | tail -40
echo NINJA_EXIT=%ERRORLEVEL%
pause
