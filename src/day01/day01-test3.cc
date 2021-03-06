#include <vector>
#include <set>
#include "process.hh"
#include <boost/ut.hpp>

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

    "returns product for input of four numbers, bad number second"_test = [] {
        auto input = std::vector<int>{2, 2000, 3, 2015};
        auto result = process3(input.begin(), input.end());
        expect(that % result == 12090);
    };

    "returns product for input of four numbers, bad number first"_test = [] {
        auto input = std::vector<int>{2000, 2, 3, 2015};
        auto result = process3(input.begin(), input.end());
        expect(that % result == 12090);
    };

    "returns correct value from the example"_test = [] {
        auto input = std::vector<int>{1721, 979, 366, 299, 675, 1456};
        auto result = process3(input.begin(), input.end());
        expect(that % result == 241861950);
    };

    return 0;
}
