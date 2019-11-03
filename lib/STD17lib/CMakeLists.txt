project(STD17lib)

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
        include/STD17lib/library.h
        include/STD17lib/network.h
        )

set(SourceFiles
        ${PLATFORM_SourceFiles}
        src/library.cpp
        )

include_directories(include)
add_library(STD17lib ${SourceFiles} ${HeaderFiles})
