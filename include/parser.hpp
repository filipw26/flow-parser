#pragma once

#include <expected>

#include "ast.hpp"
#include "query.hpp"

class Parser {
    using Queries = query::ast::Queries;
    using ParseError = int;
    using Result = std::expected<Queries, ParseError>;

public:
    static Result parse(std::string_view input) noexcept;
};
