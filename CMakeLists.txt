cmake_minimum_required(VERSION 3.0)
project(my_json)

set(CMAKE_BUILD_TYPE DEBUG)

add_subdirectory(src)

include_directories(include)

link_directories(lib)

add_executable(test_0 test/test_0.cpp)
target_link_libraries(test_0 PUBLIC SRC_LIST)

add_executable(test_literal test/test_literal.cpp)
target_link_libraries(test_literal PUBLIC SRC_LIST)
target_link_libraries(test_literal PUBLIC libgtest.a libgtest_main.a pthread)