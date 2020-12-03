#include <vector>
#include <boost/ut.hpp>

template <typename I>
auto process(I, I) {
    return 0;
}

auto main() -> int {
    using namespace boost::ut;

    "returns 0 for empty input"_test = [] {
        std::vector<int> input {};
        auto result = process(input.begin(), input.end());
        expect(that % result == 0);
    };
    return 0;
}
