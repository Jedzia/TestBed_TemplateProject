@title Launching Clion with 'mipsel-unknown-linux-gnu' settings.
@REM call C:\D\dmd2vars64ldc2.bat
call setvars-mipsel-unknown-linux-gnu.bat
@echo starting up Clion ...

start "" "C:\Program Files\JetBrains\CLion 2019.2.3\bin\clion64.exe"

@REM sleep 8 seconds
@PING localhost -n 9 >NUL
