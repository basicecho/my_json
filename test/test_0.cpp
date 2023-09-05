#include "leptjson.h"
using namespace my_json;

#include <iostream>
#include <cstdio>

int count = 0;
int pass = 0;

#define TEST(expect, actuall) \
do {\
    count++;\
    if(expect == actuall) {\
        pass++;\
    }\
    else {\
        std::cout << __FILE__ << "  " << __LINE__ << "  "\
         "expect = " << expect << " ,actuall = " << actuall << std::endl;\
    }\
}while(0)

#define TEST_ACCEPT(actuall) \
do {\
    lept_value value;\
    TEST(LEPT_PARSE_EXPECT_VALUE, lept_parse(value, actuall));\
}while(0)

#define TEST_WORNG(actuall) \
do {\
    lept_value value;\
    TEST(LEPT_PARSE_INVALID_VALUE, lept_parse(value, actuall));\
}while(0)

void test_accept() {
    TEST_ACCEPT("");
    TEST_ACCEPT("  ");
    TEST_ACCEPT("  \n\n");
}

void test_worng() {
    TEST_WORNG("--T");
    TEST_WORNG("9I032");
}

int main() {
    test_accept();
    test_worng();
    printf("This result is:  %d/%d = %.3lf%%\n", pass, count, 100.0 * pass / count);
    return 0;
}