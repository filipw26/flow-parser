#pragma once

#include <boost/spirit/home/x3.hpp>

#include "ast.hpp"

namespace query {
    namespace x3 = boost::spirit::x3;

    namespace parser {
        using select_type = x3::rule<class select_id, ast::select>;
        using query_type = x3::rule<class query_id, ast::query>;
        BOOST_SPIRIT_DECLARE(query_type, select_type)
    }

    parser::query_type const& query();
    // parser::select_type const& select();
}