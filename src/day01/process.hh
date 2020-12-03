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

#endif
