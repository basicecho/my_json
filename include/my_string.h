#pragma once 

#include "leptjson.h"
using namespace my_json;

namespace my_json {
    int lept_parse_string(lept_value & value, lept_content & con);
    void lept_set_string(lept_value & value, const char * s, size_t size);
    char * lept_get_string(const lept_value & value);
    int lept_get_string_length(const lept_value & value);
    char & lept_get_string_id(const lept_value & value, int index);
}