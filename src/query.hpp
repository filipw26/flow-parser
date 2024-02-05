#pragma once

#include <boost/spirit/home/x3.hpp>

#include "ast.hpp"
#include "error_handler.hpp"

namespace query {
    namespace x3 = boost::spirit::x3;

    namespace parser {
        struct queries_id : error_handler {};

        using QueriesRule = x3::rule<queries_id, ast::Queries>;
        BOOST_SPIRIT_DECLARE(QueriesRule)
    }

    parser::QueriesRule const& queries();
}