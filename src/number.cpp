#include "number.h"

#include <string>
#include <iostream>

int my_json::lept_parse_number(lept_value & value, lept_content & con) {
    size_t p = 0;
    try {
        double number_double = std::stod(con.json, &p);
        value.n_double = number_double;
        con.json += p;
        value.type = LEPT_NUMBER_DOUBLE;
        return LEPT_PARSE_OK;
    }
    catch(const std::invalid_argument&) {
        value.type = LEPT_NULL;
        return LEPT_PARSE_INVALID_VALUE;
    }
}

auto my_json::lept_get_number(const lept_value & value) 
        -> decltype((value.type == LEPT_NUMBER_INT) ? value.n_int : value. n_double) {
        
    if(value.type == LEPT_NUMBER_INT) {
        return value.n_int;
    }
    else if(value.type == LEPT_NUMBER_DOUBLE) {
        return value.n_double;
    }
    else{
        throw std::invalid_argument("The is not a number type");
    }
}

void my_json::lept_set_number_int(lept_value & value, int target) {
    lept_free(value);
    value.type = LEPT_NUMBER_INT;
    value.n_int = target;
}

void my_json::lept_set_number_double(lept_value & value, double target) {
    lept_free(value);
    value.type = LEPT_NUMBER_DOUBLE;
    value.n_double = target;
}