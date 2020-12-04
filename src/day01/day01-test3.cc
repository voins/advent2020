#include <vector>
#include "process.hh"
#include <boost/ut.hpp>

template <typename I>
auto process3(I, I) {
    return 0;
}

auto main() -> int {
    using namespace boost::ut;

    "returns 0 for empty input"_test = [] {
        auto input = std::vector<int>{};
        auto result = process3(input.begin(), input.end());
        expect(that % result == 0);
    };

    "returns 0 for input of one number"_test = [] {
        auto input = std::vector<int>{2020};
        auto result = process3(input.begin(), input.end());
        expect(that % result == 0);
    };

    "returns 0 for input of two numbers"_test = [] {
        auto input = std::vector<int>{1, 2019};
        auto result = process3(input.begin(), input.end());
        expect(that % result == 0);
    };

    return 0;
}
