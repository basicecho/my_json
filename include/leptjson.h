#pragma once

namespace my_json{

    enum lept_type {
        LEPT_NULL,
        LEPT_FALSE,
        LEPT_TRUE,
        LEPT_STRING,
        LEPT_ARRAY,
        LEPT_OBJECT
    };

    struct lept_content {
        const char * json;
    };

    struct lept_value {

        lept_value(){type = LEPT_NULL;}

        lept_type type;
    };

    enum {
        LEPT_PARSE_OK,
        LEPT_PARSE_EXPECT_VALUE,
        LEPT_PARSE_INVALID_VALUE,
        LEPT_PARSE_END_NOT_EMPTY
    };

    int lept_parse(lept_value & value, const char * json);
    lept_type lept_get_type(const lept_value & value);

}