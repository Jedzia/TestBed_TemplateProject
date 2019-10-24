@echo off
call setvars-mipsel-unknown-linux-gnu.bat

REM call C:\D\ldc2vars64.bat
rem e:
rem cd E:\Projects\D

echo .
echo .
echo -DCMAKE_SYSTEM_NAME=Linux
echo xargo build --target=mipsel-unknown-linux-gnu
echo cargo build --target=x86_64-pc-windows-gnu
echo .
cmd