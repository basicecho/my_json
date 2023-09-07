#include "leptjson.h"
#include "my_string.h"
#include "gtest/gtest.h"

#include <iostream>
#include <cstddef>

using namespace my_json;

// 不能直接将地址进行比较，而是要比较内容

#define TEST_STRING(target, expect) \
do {\
    lept_value value;\
    EXPECT_EQ(lept_parse(value, target), LEPT_PARSE_OK);\
    EXPECT_EQ(lept_get_string_length(value), strlen(expect));\
    EXPECT_EQ(lept_get_type(value), LEPT_STRING);\
    size_t len = lept_get_string_length(value);\
    for(size_t i = 0; i < len; i++) {\
        EXPECT_EQ(expect[i], lept_get_string_id(value, i));\
    }\
} while(0)

/*
    
*/

TEST(TESTCASE1, TEST_OK_STRING) {
    TEST_STRING("\"abc\"", "abc");
    TEST_STRING("\"\\\"\\\\\\/\\b\\f\\n\\r\\t\"", "\"\\/\b\f\n\r\t");
}

int main(int argc, char * argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}