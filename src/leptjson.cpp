#include "leptjson.h"
#include "util.h"

#include <iostream>

using namespace my_json;

int lept_parse_value(lept_value & value, lept_content & con) {
    switch(*con.json) {
        case '\0':  return LEPT_PARSE_EXPECT_VALUE;
        default:    return LEPT_PARSE_INVALID_VALUE;
    }
}

int my_json::lept_parse(lept_value & value, const char * json) {
    lept_content con;
    con.json = json;
    lept_parse_whitespace(con);
    return lept_parse_value(value, con);
}

lept_type my_json::lept_get_type(const lept_value & value) {
    return value.type;
}