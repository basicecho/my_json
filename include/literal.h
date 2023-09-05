#pragma once

#include "leptjson.h"
using namespace my_json;

namespace my_json {
    int lept_parse_literal(lept_value & value, lept_content & con, const char * literal, lept_type type);
}