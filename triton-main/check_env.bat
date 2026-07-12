@echo off
echo === Checking MSVC environment ===
call "C:\Program Files\Microsoft Visual Studio\18\Community\VC\Auxiliary\Build\vcvars64.bat"
echo INCLUDE:
echo %INCLUDE%
echo.
echo LIB:
echo %LIB%
echo.
echo Checking stddef.h:
dir "%VCToolsInstallDir%include\stddef.h" 2>nul
if exist "%VCToolsInstallDir%include\stddef.h" (echo stddef.h found in MSVC) else (echo stddef.h NOT found in MSVC!)
dir "C:\Program Files (x86)\Windows Kits\10\include\10.0.26100.0\ucrt\stddef.h" 2>nul
if exist "C:\Program Files (x86)\Windows Kits\10\include\10.0.26100.0\ucrt\stddef.h" (echo stddef.h found in SDK) else (echo stddef.h NOT found in SDK!)
echo.
echo === Debug cl.exe search order ===
echo VCToolsInstallDir=%VCToolsInstallDir%
echo WindowsSdkDir=%WindowsSdkDir%
echo UniversalCRTSdkDir=%UniversalCRTSdkDir%
echo UCRTVersion=%UCRTVersion%
pause
