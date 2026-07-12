@echo off
call "C:\Program Files\Microsoft Visual Studio\18\Community\VC\Auxiliary\Build\vcvars64.bat"
cd /d "C:\Users\Glimmer\Documents\triton-lshq\triton-main_old"
D:\ComfyUI-aki-v2\python\python.exe -m pip install .\python\ --verbose --no-build-isolation
