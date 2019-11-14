set(SourceFiles
        main.cpp
        MyClass.cpp
        usercode.cpp)

#message(WARNING "XXX ${STD17lib_SOURCE_DIR}")
include_directories(${STD17lib_SOURCE_DIR}/include)
include_directories(${CBreadBoard_SOURCE_DIR}/include)
add_executable(ArduinoExample01 ${SourceFiles} MyClass.h)
target_link_libraries(ArduinoExample01 STD17lib)
if (WIN32)
    target_link_libraries(ArduinoExample01 STD17lib CBreadBoard wsock32)
endif()
