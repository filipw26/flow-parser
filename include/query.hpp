#pragma once

#include <boost/spirit/home/x3.hpp>

#include "ast.hpp"

namespace query {
    namespace x3 = boost::spirit::x3;

    namespace parser {
        using QueriesRule = x3::rule<class queries_id, ast::Queries>;
        BOOST_SPIRIT_DECLARE(QueriesRule)
    }

    parser::QueriesRule const& queries();
}