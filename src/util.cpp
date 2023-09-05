#include "util.h"

void my_json::lept_parse_whitespace(lept_content & con) {
    const char * p = con.json;
    while(*p == '\n' || *p == '\t' || *p == '\r' || *p == ' ')p++;
    con.json = p;
}