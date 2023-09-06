#pragma once

namespace my_json{

    enum lept_type {
        LEPT_NULL,
        LEPT_FALSE,
        LEPT_TRUE,
        LEPT_NUMBER_INT,
        LEPT_NUMBER_DOUBLE,
        LEPT_STRING,
        LEPT_ARRAY,
        LEPT_OBJECT
    };

    struct lept_content {
        const char * json;
        const char * stack;
        size_t size;
        size_t top;
    };

    struct lept_value {

        lept_value(){type = LEPT_NULL;}

        lept_type type;

        union {
            int n_int;
            double n_double;

            struct {
                char * s;
                size_t len;
            }s;


        };
    };

    enum {
        LEPT_PARSE_OK,
        LEPT_PARSE_EXPECT_VALUE,
        LEPT_PARSE_INVALID_VALUE,
        LEPT_PARSE_END_NOT_EMPTY
    };

    int lept_parse(lept_value & value, const char * json);
    lept_type lept_get_type(const lept_value & value);

    void lept_free(lept_value & value);

}