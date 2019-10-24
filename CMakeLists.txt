cmake_minimum_required(VERSION 3.15)
project(STD17)

#set(CMAKE_VERBOSE_MAKEFILE ON)
set(CMAKE_CXX_STANDARD 17)


#set(VUDUO_C_FLAGS "${VUDUO_C_FLAGS} -msoft-float -mips32r2 -EL")
set(VUDUO_C_FLAGS "${VUDUO_C_FLAGS} -mips32 -EL")

#set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -O0 -ggdb")
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${VUDUO_C_FLAGS}")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${VUDUO_C_FLAGS}")
#Set Linker flags
#set(CMAKE_EXE_LINKER_FLAGS "${VUDUO_C_FLAGS} -static-libgcc -static-libstdc++ -static")
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -EL")

add_executable(STD17 main.cpp)