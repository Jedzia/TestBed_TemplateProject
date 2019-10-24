REM call C:\D\dmd2vars64ldc2.bat

REM Used by gdb to refer to your master C:\Users\<USER>\.gdbinit
set HOME=%USERPROFILE%

set PATH=C:\Toolchain\MIPS\mips-2016.05\bin;C:\Toolchain\mingw-w64\x86_64-6.2.0-posix-seh-rt_v5-rev1\mingw64\bin;C:\msys64\usr\bin;%PATH%

set CC=mips-linux-gnu-gcc
set CXX=mips-linux-gnu-g++
set CFLAGS_mipsel-unknown-linux-gnu=-EL -mips32 -msoft-float
set CXXFLAGS_mipsel-unknown-linux-gnu=-EL -mips32 -msoft-float
set AR_mipsel-unknown-linux-gnu=mips-linux-gnu-ar

set OPENSSL_DIR=C:\Toolchain\MIPS\openssl\usr

set MAKEFLAGS=-j8

start "" "C:\Program Files\JetBrains\CLion 2019.2.3\bin\clion64.exe"
