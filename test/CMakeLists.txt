
project(Google_tests)
add_subdirectory(googletest)
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})


# ADD OUR TEST EXECUTABLES
set(SOURCE_FILES main_test.cpp)
add_executable(main_test main_test.cpp)
#target_link_libraries(main_test ${Boost_LIBRARIES})
target_link_libraries(main_test)
# OUR TEST NEEDS THIS EXECUTABLE TO BE BUILT FIRST...
add_dependencies(main_test STD17)

# ADD OUR TESTS
add_test(NAME test_main COMMAND main_test)

# adding the Google_Tests_run target
add_executable(Google_Tests_run GoogleTest1.cpp)

# linking Google_Tests_run with DateConverter_lib which will be tested
#target_link_libraries(Google_Tests_run DateConverter_lib)

target_link_libraries(Google_Tests_run gtest gtest_main)