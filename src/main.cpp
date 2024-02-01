#include <iostream>

#include <fmt/ranges.h>

#include "ast.hpp"
#include "query.hpp"

// template<typename ... Ts>                                                 // (7)
// struct Overload : Ts ... {
//     using Ts::operator() ...;
// };
// template<class... Ts> Overload(Ts...) -> Overload<Ts...>;

int main() {
    namespace x3 = boost::spirit::x3;

    std::string input{"select abc , bcd from tab;"};

    // query::parser::query > Grammar
    query::ast::query ast; // Tree

    using x3::ascii::space;
    auto iter = input.cbegin();
    auto const end = input.cend();

    if (phrase_parse(iter, end, query::query(), space, ast) && iter == end) {
        std::cout << "Parsing succeeded\n";
        // fmt::println("{}", word);
        std::visit([](query::ast::select const& q) {
            fmt::println("Columns: {}, Table: {}", q.columns, q.table);
        }, ast);
        return 0;
    } else {
        std::cout << "Parsing failed\n";
        std::cout << "Stopped at: " << std::string{iter, end} << '\n';
        return 1;
    }

    return 0;
}
