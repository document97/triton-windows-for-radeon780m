@echo off
cd /d "C:\Users\Glimmer\Documents\triton-lshq\triton-main_old"
echo === Checking build state ===
if exist python\build\cmake.win-amd64-cpython-3.12\build.ninja (
    echo build.ninja: YES
) else (
    echo build.ninja: NO
)
if exist python\build\cmake.win-amd64-cpython-3.12\CMakeCache.txt (
    echo CMakeCache.txt: YES
) else (
    echo CMakeCache.txt: NO
)
echo === cmake build dir contents ===
dir python\build\cmake.win-amd64-cpython-3.12 /B /A-D 2>nul | findstr /V "CMakeFiles" | head -20
echo === build output ===
dir python\build\*.log python\build\cmake.win-amd64-cpython-3.12\*.log 2>nul
echo === looking for .whl files ===
dir python\dist\*.whl 2>nul
dir python\*.whl 2>nul
echo === looking for error in recent output ===
if exist python\build\cmake.win-amd64-cpython-3.12\build.ninja (
    cd python\build\cmake.win-amd64-cpython-3.12
    ninja -n 2>&1 | findstr /V "ninja" | head -5
)
pause
