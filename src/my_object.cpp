#include "my_object.h"
#include "my_string.h"
#include "util.h"

#include <iostream>
#include <cstring>

using namespace my_json;

int my_json::lept_parse_object(lept_value & value, lept_content & con) {
    if(*con.json != '{') {
        throw std::logic_error("The parse object is worng");
    }
    else con.json++;

    int ret;
    size_t size = 0;

    lept_parse_whitespace(con);
    if(*con.json == '}') {
        con.json++;
        value.type = LEPT_OBJECT;
        value.o.a = nullptr;
        value.o.len = 0;
        return LEPT_PARSE_OK;
    }

    while(true) {
        lept_parse_whitespace(con);
        char ch = *con.json;

        if(ch != '\"') {
            throw std::logic_error("The json is invalid object, lcak \"");
        }
        lept_mapper element;
        ret  = lept_parse_get_string(con, element.key, element.klen);
        if(ret != LEPT_PARSE_OK)break;
        
        lept_parse_whitespace(con);
        ch = *con.json;
        if(ch != ':') {
            throw std::logic_error("The josn is invalid object, lcak : ");
        }
        else con.json++;

        ret = lept_parse_value(element.value, con);
        if(ret != LEPT_PARSE_OK)break;
        memcpy(lept_push_content(con, sizeof(element)), &element, sizeof(element));
        size++;
        
        lept_parse_whitespace(con);
        if(*con.json == ',') {
            con.json++;
        }
        else if(*con.json == '}') {
            con.json++;
            value.type = LEPT_OBJECT;
            value.o.len = size;
            value.o.a = new lept_mapper[size];
            size *= sizeof(lept_mapper);
            memcpy(value.o.a, lept_pop_content(con, size), size);
            return LEPT_PARSE_OK;
        }
        else {
            throw std::logic_error("The josn is invalid object, lcak } ");
        }
    }
    for(size_t i = 0; i < size; i++) {
        lept_mapper & temp = *(lept_mapper *)lept_pop_content(con, sizeof(lept_mapper));
        lept_free(temp.value);
        delete [] temp.key;
        temp.klen = 0;
    }
    return ret;
}

int my_json::lept_object_get_length(const lept_value & value) {
    if(value.type != LEPT_OBJECT) {
        throw std::logic_error("The value type is not object");
    }
    return value.o.len;
}

lept_mapper & my_json::lept_object_get_index(const lept_value & value, int index) {
    if(value.type != LEPT_OBJECT) {
        throw std::logic_error("The value type is not object");
    }
    if(index >= value.o.len) {
        throw std::out_of_range("The object size is too small");
    }
    return value.o.a[index];
}