#include "leptjson.h"
#include "my_array.h"
#include "literal.h"

#include "gtest/gtest.h"



TEST(TestCase1, TEST_EMPTY) {
    lept_value value;
    EXPECT_EQ(lept_parse(value, "[]"), LEPT_PARSE_OK);
    EXPECT_EQ(lept_get_type(value), LEPT_ARRAY);
    EXPECT_EQ(lept_get_array_length(value), 0);
}

TEST(TestCase2, TEST_TOW) {
    lept_value value;
    EXPECT_EQ(lept_parse(value, "[[]]"), LEPT_PARSE_OK);
    EXPECT_EQ(lept_get_type(value), LEPT_ARRAY);
    EXPECT_EQ(lept_get_array_length(value), 1);
    lept_value value2 = lept_get_array_id(value, 0);
    EXPECT_EQ(lept_get_type(value2), LEPT_ARRAY);
    EXPECT_EQ(lept_get_array_length(value2), 0);
}

TEST(TestCase3, TEST_TOW) {
    lept_value value;
    EXPECT_EQ(lept_parse(value, "[null, false]"), LEPT_PARSE_OK);
    EXPECT_EQ(lept_get_type(value), LEPT_ARRAY);
    EXPECT_EQ(lept_get_array_length(value), 2);

    lept_value value1 = lept_get_array_id(value, 0);
    EXPECT_EQ(lept_get_type(value1), LEPT_NULL);
    lept_value value2 = lept_get_array_id(value, 1);
    EXPECT_EQ(lept_get_type(value2), LEPT_FALSE);
}