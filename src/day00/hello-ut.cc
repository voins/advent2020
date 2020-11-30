#include <boost/ut.hpp>

auto main() -> int {
    using namespace boost::ut;

    "[hello]"_test = [] {
        auto answer = 42;

        expect(that % answer == 42);
    };
    return 0;
}
