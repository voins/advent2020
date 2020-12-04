#ifndef PROCESS_HH
#define PROCESS_HH
#include <set>

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

template <typename I>
auto process3(I first, I last) {
    while (first != last) {
        auto part_a = *first;
        auto second = ++first;
        auto parts = std::set<int>{};

        while (second != last) {
            if (parts.count(2020 - part_a - *second))
                return (2020 - part_a - *second) * part_a * *second;

            parts.insert(*second);
            second++;
        }
    }

    return 0;
}

#endif
