#include "leptjson.h"
#include "util.h"
#include "literal.h"
#include "number.h"
#include "my_string.h"
#include "my_array.h"

#include <iostream>

using namespace my_json;

int my_json::lept_parse_value(lept_value & value, lept_content & con) {
    switch(*con.json) {
        case '\0':  return LEPT_PARSE_EXPECT_VALUE;
        case 'n':   return lept_parse_literal(value, con, "null", LEPT_NULL);
        case 'f':   return lept_parse_literal(value, con, "false", LEPT_FALSE);
        case 't':   return lept_parse_literal(value, con, "true", LEPT_TRUE);
        default:    return lept_parse_number(value, con);
        case '\"':  return lept_parse_string(value, con);
        case '[':   return lept_parse_array(value, con);
    }
}

int my_json::lept_parse(lept_value & value, const char * json) {
    lept_content con;
    con.json = json;
    con.top = 0;
    con.size = 0;
    con.stack = nullptr;
    lept_parse_whitespace(con);
    int ret = lept_parse_value(value, con);
    if(ret == LEPT_PARSE_OK) {
        lept_parse_whitespace(con);
        if(*con.json != '\0') {
            value.type = LEPT_NULL;
            ret = LEPT_PARSE_END_NOT_EMPTY;
        }
    }
    return ret;
}

lept_type my_json::lept_get_type(const lept_value & value) {
    return value.type;
}

void my_json::lept_free(lept_value & value) {
    if(value.type == LEPT_STRING && value.s.len != 0) {
        delete [] value.s.s;
        value.s.s = nullptr;
        value.s.len = 0;
    }
    else if(value.type == LEPT_ARRAY && value.a.len != 0) {
        for(size_t i = 0; i < value.a.len; i++) {
            lept_free(value.a.a[i]);
        }
        delete [] value.a.a;
        value.a.a = nullptr;
        value.a.len = 0;
    }
    value.type = LEPT_NULL;
}