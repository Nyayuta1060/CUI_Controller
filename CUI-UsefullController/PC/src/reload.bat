@echo off
:RESTART
set /p yn_check="Do you want to reloading? (y/n)"
IF %yn_check:Y=Y%==Y (
  echo "Starting reload..."
  GOTO main
) ELSE IF %yn_check:N=N%==N  (
  echo "Stop reload"
  GOTO finish
) ELSE (
  echo "Please input y or n"
GOTO RESTART
)

:main
del .\main.exe
g++ main.cpp -o main
if %errorlevel% neq 0 exit /b %errorlevel%
echo "Reload success"
GOTO finish

:finish
pause
exit