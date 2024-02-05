#include <gtest/gtest.h>

#include <string>

#include "parser.hpp"

TEST(ParserTest, RequiresSemicolon) {
    std::string const validSelect{"select name from person;"};
    std::string const invalidSelect{"select name from person"};

    EXPECT_TRUE(Parser::parse(validSelect));
    EXPECT_FALSE(Parser::parse(invalidSelect));
}