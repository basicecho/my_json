#include "gtest/gtest.h"
#include "leptjson.h"
#include "my_object.h"
#include "my_array.h"
#include "my_string.h"

#include <iostream>

using namespace my_json;

TEST(CASE1, OK) {
    lept_value value;
    EXPECT_EQ(lept_parse(value, "{}"), LEPT_PARSE_OK);
    EXPECT_EQ(lept_get_type(value), LEPT_OBJECT);
    EXPECT_EQ(lept_object_get_length(value), 0);
}

TEST(CASE2, OK) {
    lept_value value;
    EXPECT_EQ(lept_parse(value, "{\"ab\":{},\"abc\":[null,null]}"), LEPT_PARSE_OK);
    EXPECT_EQ(lept_get_type(value), LEPT_OBJECT);
    EXPECT_EQ(lept_object_get_length(value), 2);

    lept_mapper & temp1 = lept_object_get_index(value, 0);
    EXPECT_EQ(temp1.key[0], 'a');
    EXPECT_EQ(temp1.key[1], 'b');
    EXPECT_EQ(temp1.klen, 2);
    EXPECT_EQ(lept_get_type(temp1.value), LEPT_OBJECT);
    EXPECT_EQ(lept_object_get_length(temp1.value), 0);

    lept_mapper & temp2 = lept_object_get_index(value, 1);
    EXPECT_EQ(temp2.key[0], 'a');
    EXPECT_EQ(temp2.key[1], 'b');
    EXPECT_EQ(temp2.key[2], 'c');
    EXPECT_EQ(temp2.klen, 3);
    EXPECT_EQ(lept_get_type(temp2.value), LEPT_ARRAY);
    EXPECT_EQ(lept_get_array_length(temp2.value), 2);
}
