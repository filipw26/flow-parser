#include "query_def.hpp"

namespace query::parser {
    using IteratorType = std::string_view::const_iterator;
    using PhraseContextType = x3::phrase_parse_context<x3::ascii::space_type>::type;
    using Context = x3::context<
        x3::error_handler_tag,
        std::reference_wrapper<x3::error_handler<IteratorType>>,
        PhraseContextType
    >;

    BOOST_SPIRIT_INSTANTIATE(QueriesRule, IteratorType, Context)
}