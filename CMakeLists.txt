cmake_minimum_required(VERSION 3.0)
project(my_json)

set(CMAKE_BUILD_TYPE DEBUG)

add_subdirectory(src) # 直接链接，不用导入头文件所在的地址了
link_directories(lib) # 不用写CMakeLists.txt，直接进行链接就可以了

set(gtest libgtest.a libgtest_main.a)

# 设置编译选项
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pthread -o2 -Wall")
set(gtest libgtest.a libgtest_main.a)

# 测试样例
add_executable(test_0 test/test_0.cpp)
target_link_libraries(test_0 PUBLIC SRC_LIST gtest)

add_executable(test_literal test/test_literal.cpp)
target_link_libraries(test_literal PUBLIC SRC_LIST gtest)

add_executable(test_number test/test_number.cpp)
target_link_libraries(test_number PUBLIC SRC_LIST gtest)

add_executable(test_string test/test_string.cpp)
target_link_libraries(test_string PUBLIC SRC_LIST gtest)

add_executable(test_array test/test_array.cpp test/gtest_main.cpp)
target_link_libraries(test_array PUBLIC SRC_LIST gtest)

add_executable(test_object test/test_object.cpp test/gtest_main.cpp)
target_link_libraries(test_object PUBLIC SRC_LIST gtest)