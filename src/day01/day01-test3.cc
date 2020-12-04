#include <vector>
#include "process.hh"
#include <boost/ut.hpp>

template <typename I>
auto process3(I first, I last) {
    if (first == last)
        return 0;

    auto part_a = *first;
    ++first;

    if (first == last)
        return 0;

    auto part_b1 = *first;
    ++first;

    if (first == last)
        return 0;

    if (part_a + part_b1 + *first == 2020)
        return part_a * part_b1 * *first;

    auto part_b2 = *first;
    ++first;

    if (first == last)
        return 0;

    if (part_a + part_b1 + *first == 2020)
        return part_a * part_b1 * *first;

    if (part_a + part_b2 + *first == 2020)
        return part_a * part_b2 * *first;
    
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

    "returns product for input of three numbers summing to 2020"_test = [] {
        auto input = std::vector<int>{2, 3, 2015};
        auto result = process3(input.begin(), input.end());
        expect(that % result == 12090);
    };

    "returns 0 for input of three numbers not summing to 2020"_test = [] {
        auto input = std::vector<int>{2, 3, 2014};
        auto result = process3(input.begin(), input.end());
        expect(that % result == 0);
    };

    "returns product for input of four numbers, bad number third"_test = [] {
        auto input = std::vector<int>{2, 3, 2000, 2015};
        auto result = process3(input.begin(), input.end());
        expect(that % result == 12090);
    };

    return 0;
}
