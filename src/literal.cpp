#include "literal.h"

#include <cstddef>

int my_json::lept_parse_literal(lept_value & value, lept_content & con, const char * literal, lept_type type) {
    // 不需要去获取长度，直接判断是否为空就行了
    for(size_t i = 0; literal[i]; i++) {
        if(literal[i] == *con.json) {
            con.json++;
        }
        else {
            value.type = LEPT_NULL;
            return LEPT_PARSE_INVALID_VALUE;
        }
    }
    value.type = type;
    return LEPT_PARSE_OK;
}