#include <gtest/gtest.h>

#include "parser.hpp"

using Select = query::ast::Select;

TEST(SelectTest, SingleColumn) {
    std::string const input{"select name from person;"};

    auto const result = Parser::parse(input);

    ASSERT_TRUE(result);
    ASSERT_FALSE(result->empty());
    EXPECT_TRUE(std::holds_alternative<Select>(result->at(0)));
}

TEST(SelectTest, MultipleColumns) {
    std::string const input{"select name, surname from person;"};

    auto const result = Parser::parse(input);

    ASSERT_TRUE(result);
    ASSERT_FALSE(result->empty());
    EXPECT_TRUE(std::holds_alternative<Select>(result->at(0)));
}

TEST(SelectTest, Asterisk) {
    std::string const input{"select * from person;"};

    auto const result = Parser::parse(input);

    ASSERT_TRUE(result);
    ASSERT_FALSE(result->empty());
    EXPECT_TRUE(std::holds_alternative<Select>(result->at(0)));
}

TEST(SelectTest, RequiresTableName) {
    std::string const input{"select name from;"};

    EXPECT_FALSE(Parser::parse(input));
}

TEST(SelectTest, RequiresAtLeastOneColumn) {
    std::string const input{"select from person;"};

    EXPECT_FALSE(Parser::parse(input));
}

TEST(SelectTest, DoesntAllowAsteriskWithIdentifier) {
    std::string const input{"select *, name from person;"};
    std::string const input2{"select name, * from person;"};

    EXPECT_FALSE(Parser::parse(input));
    EXPECT_FALSE(Parser::parse(input2));
}