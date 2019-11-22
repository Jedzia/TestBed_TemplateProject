cmake_minimum_required(VERSION 3.14)
project(TestBed_MCU)

#set(CMAKE_VERBOSE_MAKEFILE ON)
set(CMAKE_CXX_STANDARD 17)

#message(WARNING "CMAKE_SYSTEM=${CMAKE_SYSTEM}")
#message(WARNING "CMAKE_SYSTEM_NAME=${CMAKE_SYSTEM_NAME}")

if (CMAKE_SYSTEM STREQUAL "Linux")
    #set(VUDUO_C_FLAGS "${VUDUO_C_FLAGS} -msoft-float -mips32r2 -EL")
    set(VUDUO_C_FLAGS "${VUDUO_C_FLAGS} -mips32 -EL")

    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${VUDUO_C_FLAGS}")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${VUDUO_C_FLAGS}")

    #Set Linker flags
    #set(CMAKE_EXE_LINKER_FLAGS "${VUDUO_C_FLAGS} -static-libgcc -static-libstdc++ -static")
    set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -EL")

    message("Building MIPS target with ${VUDUO_C_FLAGS}")
endif ()

if (CMAKE_SYSTEM_NAME STREQUAL "Windows")
    #SET(GCC_PROJECT_FLAGS "--enable-clocale")
    #SET(GCC_PROJECT_LINK_FLAGS    "--enable-clocale")

    #SET(CMAKE_C_FLAGS  "${CMAKE_C_FLAGS} ${GCC_PROJECT_FLAGS}")
    #SET(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} ${GCC_PROJECT_FLAGS}")
    #SET(CMAKE_EXE_LINKER_FLAGS  "${CMAKE_EXE_LINKER_FLAGS} ${GCC_PROJECT_LINK_FLAGS}")
endif ()

# ENABLE TESTING WITH CMAKE'S CTEST
enable_testing()
#INCLUDE(CTest)

add_subdirectory(lib/)
add_subdirectory(src/)

# ADD OUR TESTING DIRECTORY
add_subdirectory(test/)
