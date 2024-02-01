#pragma once

#include <string>
#include <vector>
#include <variant>

namespace query::ast {

    struct select {
        std::vector<std::string> columns;
        std::string table;
    };

    using query = std::variant<select>;

}