cmake_minimum_required(VERSION 3.0)
project(my_json)

set(CMAKE_BUILD_TYPE DEBUG)

add_subdirectory(src)

include_directories(include)

add_executable(test_0 test/test_0.cpp)
target_link_libraries(test_0 PUBLIC SRC_LIST)