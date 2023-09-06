#include "util.h"

#include <cstring>
#include <iostream>

void my_json::lept_parse_whitespace(lept_content & con) {
    const char * p = con.json;
    while(*p == '\n' || *p == '\t' || *p == '\r' || *p == ' ')p++;
    con.json = p;
}

#define PUTC(con, ch) do { (*(char *)lept_push_content(con, sizeof(ch))) = (ch);} while(0)
#define PUTS(con, s, len) do { memcpy(lept_push_content(con, len), s, len);} while(0)

// 入栈操作
// 直接对头指针进行赋值操作
// 如果是字符串，则采用memcpy进行赋值
void * my_json::lept_push_content(lept_content & con, size_t size) {
    void * ret;
    if(con.top + size >= con.size) {
        if(con.size == 0)con.size = LEPT_PARSE_INIT_STACK;
        while(con.top + size >= con.size)con.size += con.size >> 1;

        // increasing capacity
        char * newStack = new char[size];
        for(size_t i = 0; i < con.top; i++) {
            newStack[i] = con.stack[i];
        }
        delete con.stack;
        con.stack = newStack;

        ret = (void *)con.stack + con.top;
        con.top += size;
    }
    return ret;
}

// 出栈是返回首地址
void * my_json::lept_pop_content(lept_content & con, size_t size) {
    if(con.top < size) {
        throw std::runtime_error("The pop operation is worng");
    }
    con.top -= size;
    return (void *)con.stack + con.top;
}