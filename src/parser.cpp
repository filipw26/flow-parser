#include "parser.hpp"

#include <boost/spirit/home/x3.hpp>

Parser::Result Parser::parse(std::string_view const input) noexcept {
    namespace x3 = boost::spirit::x3;
    using x3::ascii::space;

    Queries queries{};

    auto iter = input.cbegin();

    if(auto const end = input.cend();
        phrase_parse(iter, end, query::queries(), space, queries) && iter == end) {

        return queries;
    }

    return std::unexpected(1337);
}
