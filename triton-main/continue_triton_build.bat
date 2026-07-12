@echo off
setlocal

call "C:\Program Files\Microsoft Visual Studio\18\Community\VC\Auxiliary\Build\vcvars64.bat"
if errorlevel 1 exit /b 1

set "PATH=C:\Users\Glimmer\AppData\Local\Programs\Python\Python312\Lib\site-packages\cmake\data\bin;D:\ComfyUI-aki-v2\python\Scripts;%PATH%"
set "PATH=%PATH:E:\mingw64\bin;=%"
set "HIP_PATH=C:\Program Files\AMD\ROCm\5.7"

cd /d "%~dp0python\build\cmake.win-amd64-cpython-3.12"
cmake --build . --config TritonRelBuildWithAsserts -j 4
exit /b %ERRORLEVEL%
