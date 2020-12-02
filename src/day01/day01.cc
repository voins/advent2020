#include <fstream>
#include <optional>
#include <fmt/core.h>
#include <boost/ut.hpp>

template <typename T>
auto read(std::istream& is) -> std::optional<T> {
    auto result = T{};

    if (is >> result)
        return {result};

    return {};
}

template <typename T>
auto read_vector(std::istream& is) -> std::vector<T> {
    auto result = std::vector<int>{};

    while(is) {
        auto value = read<int>(is);
        if (value)
            result.emplace_back(*value);
    }

    return result;
}

auto main() -> int {
    auto is = std::ifstream{INPUT_FILE};
    auto input = read_vector<int>(is);
    fmt::print("{}\n", input.size());
    return 0;
}
