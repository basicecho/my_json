#pragma once

#include "leptjson.h"
#include <cstddef>

#define LEPT_PARSE_INIT_STACK 256

namespace my_json {

    void lept_parse_whitespace(lept_content & con);
    void * lept_push_content(lept_content & con, size_t size);
    void * lept_pop_content(lept_content & con, size_t size);
}