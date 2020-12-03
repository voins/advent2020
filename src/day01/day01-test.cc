#include <vector>
#include <boost/ut.hpp>

template <typename I>
auto process(I first, I last) {
    if (first == last)
        return 0;
    auto part = *first;

    first++;
    if (first == last)
        return 0;

    if (part + *first == 2020)
        return part * *first;
    
    return 0;
}

auto main() -> int {
    using namespace boost::ut;

    "returns 0 for empty input"_test = [] {
        auto input = std::vector<int>{};
        auto result = process(input.begin(), input.end());
        expect(that % result == 0);
    };

    "returns 0 for input of one number"_test = [] {
        auto input = std::vector<int>{2020};
        auto result = process(input.begin(), input.end());
        expect(that % result == 0);
    };

    "returns product for input of two numbers summing to 2020"_test = [] {
        auto input = std::vector<int>{2, 2018};
        auto result = process(input.begin(), input.end());
        expect(that % result == 4036);
    };

    "returns 0 for input of two numbers not summing to 2020"_test = [] {
        auto input = std::vector<int>{2, 2019};
        auto result = process(input.begin(), input.end());
        expect(that % result == 0);
    };
    return 0;
}
