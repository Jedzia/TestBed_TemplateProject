project(STD17lib)

set(HeaderFiles
        include/STD17lib/library.h
        include/STD17lib/network.h
        )

set(SourceFiles
        src/library.cpp
        src/platform/win/network.cpp
        )

include_directories(include)
add_library(STD17lib ${SourceFiles} ${HeaderFiles})
