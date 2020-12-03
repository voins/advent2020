#include <vector>
#include <set>
#include <boost/ut.hpp>

template <typename I>
auto process(I first, I last) {
    auto parts = std::set<int>{};

    while (first != last) {
        if (parts.count(2020 - *first))
            return (2020 - *first) * *first;

        parts.insert(*first);
        first++;
    }

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

    "returns product for input of three numbers, bad number second"_test = [] {
        auto input = std::vector<int>{2, 2019, 2018};
        auto result = process(input.begin(), input.end());
        expect(that % result == 4036);
    };

    "returns product for input of three numbersbad number first"_test = [] {
        auto input = std::vector<int>{2019, 2, 2018};
        auto result = process(input.begin(), input.end());
        expect(that % result == 4036);
    };

    "returns correct value from the example"_test = [] {
        auto input = std::vector<int>{1721, 979, 366, 299, 675, 1456};
        auto result = process(input.begin(), input.end());
        expect(that % result == 514579);
    };
    return 0;
}
