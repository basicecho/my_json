#pragma once

#include "leptjson.h"
#include "util.h"

using namespace my_json;

namespace my_json {
    int lept_parse_array(lept_value & value, lept_content & con);
    int lept_get_array_length(const lept_value & value);
    lept_value & lept_get_array_id(const lept_value & value, size_t index);
}