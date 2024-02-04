#pragma once

#include <boost/spirit/home/x3.hpp>

#include "ast_adapted.hpp"
#include "query.hpp"

namespace query::parser {
    namespace x3 = boost::spirit::x3;
    namespace ascii = x3::ascii;

    using x3::lit;
    using x3::lexeme;
    using ascii::char_;

    using QueryRule = x3::rule<class query_id, ast::Query>;
    using SelectRule = x3::rule<class select_id, ast::Select>;

    constexpr x3::rule<class select_columns_id, ast::ColumnsType> select_columns = "select_columns";
    constexpr x3::rule<class select_table_id, std::string> select_table = "select_table";
    constexpr SelectRule select = "select";
    constexpr QueryRule query = "query";
    constexpr QueriesRule queries = "queries";

    constexpr auto kw = [](char const* keyword) {
        return x3::no_case[lit(keyword)];
    };

    // General
    constexpr auto identifier = lexeme[x3::alpha >> *x3::alnum];
    constexpr auto identifierList = identifier % ',';

    // Select
    constexpr auto select_columns_def = ascii::lit('*') | identifierList;
    constexpr auto select_table_def = identifier;

    constexpr auto select_def =
        kw("select") >> select_columns >>
        kw("from") >> select_table;

    // Query
    constexpr auto query_def = select > lit(";");
    constexpr auto queries_def = *query;

    BOOST_SPIRIT_DEFINE(queries, query, select, select_columns, select_table);
}

namespace query {
    extern parser::QueriesRule const& queries() {
        return parser::queries;
    }
}
