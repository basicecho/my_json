#include "my_array.h"
#include "leptjson.h"
#include "util.h"

#include <iostream>
#include <cstring>

#define EXPECT(value) \
do {\
    if(value.type != LEPT_ARRAY) {\
        throw std::invalid_argument("The value is not a array");\
    }\
}while(0)

using namespace my_json;

int my_json::lept_parse_array(lept_value & value, lept_content & con) {
    if(*con.json != '[') {
        throw std::runtime_error("The value is a invalid array");
    }
    con.json++;
    // const char * p = con.json;
    if(*con.json == ']') {
        con.json++;
        value.type = LEPT_ARRAY;
        value.a.a = nullptr;
        value.a.len = 0;
        return LEPT_PARSE_OK;
    }
    size_t size = 0;
    int ret;
    while(true) {
        lept_value element;
        ret = lept_parse_value(element, con);
        if(ret != LEPT_PARSE_OK) break;
        memcpy((lept_value *)lept_push_content(con, sizeof(lept_value)), &element, sizeof(lept_value));
        size++;
        lept_parse_whitespace(con);
        if(*con.json == ',') {
            con.json++;
            lept_parse_whitespace(con);
        }
        else  if(*con.json == ']') {
            con.json++;
            value.type = LEPT_ARRAY;
            value.a.len = size;
            value.a.a = new lept_value[size];
            size *= sizeof(lept_value);
            memcpy(value.a.a, lept_pop_content(con, size), size);
            return LEPT_PARSE_OK;
        }
        else {
            ret = LEPT_PARSE_NOT_RIGHT_BRACKET;
            break;
        }
    }
    // 这里必须要这样子进行清空，不然从堆区开辟的空间就无法回收
    for(size_t i = 0; i < size; i++)
        lept_free(*(lept_value*)lept_pop_content(con, sizeof(lept_value)));
    value.type = LEPT_NULL;
    return ret;
}

int my_json::lept_get_array_length(const lept_value & value) {
    EXPECT(value);
    return value.a.len;
}

lept_value & my_json::lept_get_array_id(const lept_value & value, size_t index) {
    EXPECT(value);
    if(index >= value.a.len) {
        throw std::runtime_error("The array size is more small");
    }
    return value.a.a[index];
}