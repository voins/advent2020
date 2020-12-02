#ifndef MAYBE_HH
#define MAYBE_HH
#include <optional>
#include <functional>

template <typename T>
struct maybe {
    std::optional<T> value;

    maybe(): value{}
    {}

    template <typename U>
    maybe(U&& other): value{std::forward<U>(other)}
    {}

    template <typename Code,
              typename R = std::result_of_t<Code(T)>,
              typename = std::enable_if_t<std::is_void_v<R>>>
    auto then(Code&& code) -> void {
        if (value)
            std::invoke(std::forward<Code>(code), *value);
    }
};

#endif
