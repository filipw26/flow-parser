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

    using select_type = x3::rule<class select_id, ast::select>;

    constexpr x3::rule<class select_columns_id, std::vector<std::string>> select_columns = "select_columns";
    constexpr x3::rule<class select_table_id, std::string> select_table = "select_table";
    constexpr select_type select = "select";
    constexpr query_type query = "query";

    auto const identifier = lexeme[+(char_ - char_(" ,;"))];

    auto const select_columns_def = identifier % ',';
    auto const select_table_def = identifier;

    constexpr auto select_def = lit("select") >> select_columns >> lit("from") >> select_table >> lit(";");

    constexpr auto query_def = select;

    BOOST_SPIRIT_DEFINE(query, select, select_columns, select_table);
}

namespace query {
    extern parser::query_type const& query() {
        return parser::query;
    }

    // parser::select_type const& select() {
    //     return parser::select;
    // }
}