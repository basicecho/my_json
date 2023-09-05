add_library(SRC_LIST 
                leptjson.cpp 
                util.cpp
                literal.cpp
)

include_directories(${CMAKE_SOURCE_DIR}/include)

target_include_directories(SRC_LIST 
                          PUBLIC ${CMAKE__SOURCE_DIR}/include)