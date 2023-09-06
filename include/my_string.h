#pragma once 

#include "leptjson.h"
using namespace my_json;

namespace my_json {
    int lept_parse_string(lept_value & value, lept_content & con);
}