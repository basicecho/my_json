#include "literal.h"

#include <cstddef>
#include <iostream> // 标准头文件里面才有异常类
#include <string>

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

void my_json::lept_set_null(lept_value & value) {
    lept_free(value);
}

int my_json::lept_get_boolean(const lept_value & value) {
    if(value.type != LEPT_FALSE || value.type != LEPT_TRUE) {
        throw std::invalid_argument("The value is not a boolean");
    }
    return value.type;
}

void my_json::lept_set_boolean(lept_value & value, int target) {
    lept_free(value);
    value.type = target ? LEPT_TRUE : LEPT_FALSE;
}