#pragma once

#include "leptjson.h"
using namespace my_json;

namespace my_json {
    int lept_parse_object(lept_value & value, lept_content & con);
    int lept_object_get_length(const lept_value & value);
    lept_mapper & lept_object_get_index(const lept_value & value, int index);
}