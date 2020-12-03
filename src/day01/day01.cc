#include <fstream>
#include <fmt/core.h>
#include <boost/ut.hpp>
#include "maybe.hh"
#include "process.hh"

template <typename T>
auto read(std::istream& is) -> maybe<T> {
    auto result = T{};

    if (is >> result)
        return {result};

    return {};
}

template <typename T>
auto read_vector(std::istream& is) -> std::vector<T> {
    auto result = std::vector<T>{};

    while(is)
        read<T>(is)
            .then([&](auto value) {
                result.emplace_back(value);
            });

    return result;
}

auto main() -> int {
    auto is = std::ifstream{INPUT_FILE};
    auto input = read_vector<int>(is);
    fmt::print("{}\n", process(input.begin(), input.end()))‸;
    return 0;
}
