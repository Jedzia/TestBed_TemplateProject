set(SourceFiles
        main.cpp
        MyClass.cpp
        )

#message(WARNING "XXX ${STD17lib_SOURCE_DIR}")
include_directories(${STD17lib_SOURCE_DIR}/include)
add_executable(STD17 ${SourceFiles} MyClass.h)
target_link_libraries(STD17 STD17lib)
if (WIN32)
    target_link_libraries(STD17 STD17lib wsock32)
endif()
