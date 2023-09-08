#include "my_string.h"
#include "util.h"

#include <iostream>
#include <cstring>

#define EXPECT(value) \
do {\
    if(value.type != LEPT_STRING) {\
        throw std::invalid_argument("The value is not a string");\
    }\
}while(0)

// 我需要解析出来一个字符串，并且得到长度
int my_json::lept_parse_get_string(lept_content & con, char* & s, size_t & len) {
    if(*con.json == '\"')con.json++;
    else {
        throw std::invalid_argument("The is not a valid string");
    }
    size_t head = con.top;
    const char * p = con.json;
    while(true) {
        char ch;
        switch(ch = *p++) {
            case '\"':
                len = con.top - head;

                if(s != nullptr)delete [] s;
                s = new char[len + 1];
                memcpy(s, lept_pop_content(con, len), len);
                s[len] = '\0';

                con.json = p;
                return LEPT_PARSE_OK;
            case '\\':
                switch(*p++) {
                    case '\"': PUTC(con, '\"'); break;
                    case '\\': PUTC(con, '\\'); break;
                    case '/':  PUTC(con, '/' ); break;
                    case 'b':  PUTC(con, '\b'); break;
                    case 'f':  PUTC(con, '\f'); break;
                    case 'n':  PUTC(con, '\n'); break;
                    case 'r':  PUTC(con, '\r'); break;
                    case 't':  PUTC(con, '\t'); break;
                    default:
                        con.top = head;
                        return LEPT_PARSE_INVALID_VALUE;
                }
                break;
            case '\0': return LEPT_PARSE_INVALID_VALUE;
            default: PUTC(con, ch); break;
        }
    }
}

int my_json::lept_parse_string(lept_value & value, lept_content & con) {
    char * s;
    size_t len;
    int ret = lept_parse_get_string(con, s, len);
    if(ret == LEPT_PARSE_OK)lept_set_string(value, s, len);
    return ret;
}

void my_json::lept_set_string(lept_value & value, const char * s, size_t size) {
    lept_free(value);
    value.type = LEPT_STRING;
    value.s.s = new char[size + 1];
    value.s.len = size;
    memcpy(value.s.s, s, size);
    value.s.s[size] = '\0';
}

char * my_json::lept_get_string(const lept_value & value) {
    EXPECT(value);
    return value.s.s;
}

int my_json::lept_get_string_length(const lept_value & value) {
    EXPECT(value);
    return value.s.len;
}

char & my_json::lept_get_string_id(const lept_value & value, int index) {
    EXPECT(value);
    if(index >= value.s.len) {
        throw std::out_of_range("The string is small");
    }
    return value.s.s[index];
}