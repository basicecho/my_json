#include "gtest/gtest.h"

#include "leptjson.h"
using namespace my_json;

#define TEST_OK_NULL(actuall) \
do {\
    lept_value value;\
    EXPECT_EQ(lept_parse(value, actuall), LEPT_PARSE_OK);\
    EXPECT_EQ(lept_get_type(value), LEPT_NULL);\
}while(0)

#define TEST_OK_FALSE(actuall) \
do {\
    lept_value value;\
    EXPECT_EQ(lept_parse(value, actuall), LEPT_PARSE_OK);\
    EXPECT_EQ(lept_get_type(value), LEPT_FALSE);\
}while(0)

#define TEST_OK_TRUE(actuall) \
do {\
    lept_value value;\
    EXPECT_EQ(lept_parse(value, actuall), LEPT_PARSE_OK);\
    EXPECT_EQ(lept_get_type(value), LEPT_TRUE);\
}while(0)

TEST(TESTCASE1, OK_NULL) {
    TEST_OK_NULL("null");
    TEST_OK_NULL("  null  ");
}

TEST(TESTCASE2, OK_FALSE) {
    TEST_OK_FALSE("false");
    TEST_OK_FALSE("false     ");
}

TEST(TESTCASE3, OK_TRUE) {
    TEST_OK_TRUE("   true");
}

TEST(TESTCASE4, WORNG) {
    lept_value value;
    
    value.type = LEPT_FALSE;
    EXPECT_EQ(lept_parse(value, "nul"), LEPT_PARSE_INVALID_VALUE);
    EXPECT_EQ(lept_get_type(value), LEPT_NULL);

    value.type = LEPT_TRUE;
    EXPECT_EQ(lept_parse(value, "fal"), LEPT_PARSE_INVALID_VALUE);
    EXPECT_EQ(lept_get_type(value), LEPT_NULL);

    value.type = LEPT_FALSE;
    EXPECT_EQ(lept_parse(value, "tr"), LEPT_PARSE_INVALID_VALUE);
    EXPECT_EQ(lept_get_type(value), LEPT_NULL);

    value.type = LEPT_FALSE;
    EXPECT_EQ(lept_parse(value, "true  ttt"), LEPT_PARSE_END_NOT_EMPTY);
    EXPECT_EQ(lept_get_type(value), LEPT_NULL);
}



int main(int argc, char * argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}