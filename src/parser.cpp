#include "parser.hpp"

#include <iostream>

#include "query.hpp"
#include "error_handler.hpp"

#include <boost/spirit/home/x3.hpp>

Parser::Result Parser::parse(std::string_view const input) noexcept {
    namespace x3 = boost::spirit::x3;
    using x3::ascii::space;

    Queries queries{};

    using x3::with;
    using x3::error_handler_tag;
    using error_handler_type = x3::error_handler<std::string_view::const_iterator>;

    auto iter = input.cbegin();
    auto const end = input.cend();

    error_handler_type error_handler(iter, end, std::cerr);

    auto const parser = with<error_handler_tag>(std::ref(error_handler))[query::queries()];

    if(phrase_parse(iter, end, parser, space, queries) && iter == end) {

        return queries;
    }

    return std::unexpected(1337);
}
