@echo off
call setvars-mipsel-unknown-linux-gnu.bat

REM call C:\D\ldc2vars64.bat
rem e:
rem cd E:\Projects\D

echo * .
echo * .
echo * cd cmake-build-ninja
echo * cmake ../ -G"Ninja" -DCMAKE_SYSTEM_NAME=Linux
echo * ninja
echo * .
echo * cmake ../ -G"Unix Makefiles" -DCMAKE_SYSTEM_NAME=Linux
echo * make
echo * .
echo * .

cmd