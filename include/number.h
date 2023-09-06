#pragma once

#include "leptjson.h"

namespace my_json {
    int lept_parse_number(lept_value & value, lept_content & con);

    auto lept_get_number(const lept_value & value) 
        -> decltype((value.type == LEPT_NUMBER_INT) ? value.n_int : value. n_double);
    
    void lept_set_number_int(lept_value & value, int target);
    void lept_set_number_double(lept_value & value, double target);

}