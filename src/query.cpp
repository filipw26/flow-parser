#include "query_def.hpp"

namespace query::parser {
    using iterator_type = std::string::const_iterator;
    using phrase_context_type = x3::phrase_parse_context<x3::ascii::space_type>::type;

    BOOST_SPIRIT_INSTANTIATE(query_type, iterator_type, phrase_context_type)
    BOOST_SPIRIT_INSTANTIATE(select_type, iterator_type, phrase_context_type)
}