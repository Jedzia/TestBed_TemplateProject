project(CBreadBoard)

if (WIN32)
    set(PLATFORM_HeaderFiles
            )

    set(PLATFORM_SourceFiles
            src/platform/win/network.cpp
            src/platform/win/console.cpp
            src/platform/win/printlocales.cpp)
else ()
    set(PLATFORM_SourceFiles
            src/platform/linux/network.cpp
            )
endif ()

set(HeaderFiles
        ${PLATFORM_HeaderFiles}
        include/CBreadBoard/library.h
        include/CBreadBoard/network.h
        include/CBreadBoard/serial.h
        include/CBreadBoard/Arduino.h
        include/CBreadBoard/cbreadboard.h
        include/CBreadBoard/interrupt.h
        include/CBreadBoard/memory.h
        include/CBreadBoard/io.h
        include/CBreadBoard/io/input.h
        include/CBreadBoard/mcu.h
        include/CBreadBoard/console.h
        include/CBreadBoard/internal/display.h)

set(SourceFiles
        ${PLATFORM_SourceFiles}
        src/library.cpp
        src/serial.cpp
        src/Arduino.cpp
        src/interrupt.cpp
        src/memory.cpp
        src/io.cpp
        src/io/input.cpp
        src/mcu.cpp
        src/display/display.cpp)

find_package(curses REQUIRED)

include_directories(${FMT_SOURCE_DIR}/include)
include_directories(${CURSES_INCLUDE_DIR}/ncurses)
include_directories(include)

add_library(CBreadBoard ${SourceFiles} ${HeaderFiles})
target_link_libraries(CBreadBoard XInput.lib)
target_link_libraries(CBreadBoard ${CURSES_LIBRARIES})
target_link_libraries(CBreadBoard fmt::fmt)
