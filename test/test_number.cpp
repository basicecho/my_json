#include "gtest/gtest.h"
#include "leptjson.h"
#include "number.h"
using namespace my_json;

int main(int argc, char * argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

#define TEST_INT(target, expect) \
do {\
    lept_value value;\
    EXPECT_EQ(lept_parse(value, target), LEPT_PARSE_OK);\
    EXPECT_EQ(lept_get_number(value), expect);\
    EXPECT_EQ(lept_get_type(value), LEPT_NUMBER_INT);\
}while(0)

// int类型不是很好设计，暂时放一放
TEST(TESTCASE1, TEST_OK_INT) {
    // TEST_INT("1", 1);
    // TEST_INT("100", 100);
    // TEST_INT("0", 0);
    // TEST_INT("-1", -1);
}

#define TEST_DOUBLE(target, expect) \
do {\
    lept_value value;\
    EXPECT_EQ(lept_parse(value, target), LEPT_PARSE_OK);\
    EXPECT_EQ(lept_get_number(value), expect);\
    EXPECT_EQ(lept_get_type(value), LEPT_NUMBER_DOUBLE);\
}while(0)

TEST(TESTCASE2, TEST_OK_DOUBLE) {
    TEST_DOUBLE("1.1", 1.1);
    TEST_DOUBLE("0.1", 0.1);
    TEST_DOUBLE("0.0", 0.0);
    TEST_DOUBLE("2.2", 2.2);
    TEST_DOUBLE("-2.2", -2.2);
    TEST_DOUBLE("1E9", 1e9);
    // TEST_DOUBLE("1e-100000000000", 0); 
    TEST_DOUBLE("1e128", 1e128);
    TEST_DOUBLE("-1e128", -1e128);
}

#define TEST_NUMBER_WORNG(target) \
do {\
    lept_value value;\
    value.type = LEPT_FALSE;\
    EXPECT_EQ(lept_parse(value, target), LEPT_PARSE_INVALID_VALUE);\
    EXPECT_EQ(lept_get_type(value), LEPT_NULL);\
}while(0)

TEST(TESTCASE3, TEST_WORNG) {
    TEST_NUMBER_WORNG("A");
    TEST_NUMBER_WORNG("e");
}