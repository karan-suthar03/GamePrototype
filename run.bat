@echo off
setlocal

cd /D "%~dp0"

if not exist build (exit)

call build\Debug\game_prototype.exe
if errorlevel 1 (
    echo ERROR: Run Failed! 
    popd
    exit /b 1
)

endlocal
