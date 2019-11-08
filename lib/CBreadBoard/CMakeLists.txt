project(CBreadBoard)

if (WIN32)
    set(PLATFORM_HeaderFiles
            )

    set(PLATFORM_SourceFiles
            src/platform/win/network.cpp
            )
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
        )

set(SourceFiles
        ${PLATFORM_SourceFiles}
        src/library.cpp
        src/serial.cpp
        src/Arduino.cpp
        )

include_directories(include)
add_library(CBreadBoard ${SourceFiles} ${HeaderFiles})
