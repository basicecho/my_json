#pragma once

#include "leptjson.h"
using namespace my_json;

namespace my_json {
    int lept_parse_literal(lept_value & value, lept_content & con, const char * literal, lept_type type);

    void lept_set_null(lept_value & value);
    int lept_get_boolean(const lept_value & value);
    void lept_set_boolean(lept_value & value, int target);
}