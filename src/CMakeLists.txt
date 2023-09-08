add_library(SRC_LIST 
                leptjson.cpp 
                util.cpp
                literal.cpp
                number.cpp
                my_string.cpp
                my_array.cpp
                my_object.cpp
)

target_include_directories(SRC_LIST PUBLIC "${PROJECT_SOURCE_DIR}/include") # 自己进行链接