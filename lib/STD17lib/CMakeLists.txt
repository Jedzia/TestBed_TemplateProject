project(STD17lib)

set(SourceFiles
        src/library.cpp
        )

set(HeaderFiles
        include/STD17lib/library.h
        )

include_directories(include)
add_library(STD17lib ${SourceFiles} ${HeaderFiles})
