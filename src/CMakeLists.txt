add_library(SRC_LIST 
                leptjson.cpp 
                util.cpp
                literal.cpp
                number.cpp
)

target_include_directories(SRC_LIST PUBLIC "${PROJECT_SOURCE_DIR}/include") # 自己进行链接