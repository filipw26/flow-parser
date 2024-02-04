#pragma once

#include <boost/fusion/include/adapt_struct.hpp>
#include "ast.hpp"

BOOST_FUSION_ADAPT_STRUCT(query::ast::Select,
    (query::ast::ColumnsType, columns),
    (std::string, table))