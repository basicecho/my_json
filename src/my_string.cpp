#include "my_string.h"
#include <iostream>

int my_json::lept_parse_string(lept_value & value, lept_content & con) {
    if(*con.json == '\"')con.json++;
    else {
        throw std::runtime_error("The not is a string");
    }
    size_t head = con.top;
    const char * p = con.json;
    switch(*p++) {
        case '\"':
            value.s.len = con.top - head;
            
        case '\\':
        case '\0':
        default:
    }
}