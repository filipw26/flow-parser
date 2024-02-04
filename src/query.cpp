#include "query_def.hpp"

namespace query::parser {
    using IteratorType = std::string_view::const_iterator;
    using PhraseContextType = x3::phrase_parse_context<x3::ascii::space_type>::type;

    BOOST_SPIRIT_INSTANTIATE(QueriesRule, IteratorType, PhraseContextType)
}