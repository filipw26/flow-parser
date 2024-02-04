#include <fmt/ranges.h>

#include "parser.hpp"
#include "query.hpp"

int main() {
    namespace x3 = boost::spirit::x3;

    std::string const input{"select abc , bcd from tab;"};

    if (auto const result = Parser::parse(input)) {
        fmt::println("Parsed {} queries", result.value().size());
        return 0;
    }

    fmt::println("Parsing failed");
    return 1;
}
