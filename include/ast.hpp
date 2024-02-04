#pragma once

#include <string>
#include <vector>
#include <variant>

namespace query::ast {
    using ColumnsType = std::vector<std::string>;

    struct Select {
        ColumnsType columns;
        std::string table;
    };

    using Query = std::variant<Select>;
    using Queries = std::vector<Query>;

}