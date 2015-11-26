
#ifndef _AKEE_UTILS_TOSTRING_H_
#define _AKEE_UTILS_TOSTRING_H_

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

#include <string>

namespace akee {

namespace StringUtils {

// See: http://blog.chinaunix.net/uid-1720597-id-306773.html

namespace detail {

template<typename T>
struct HasToStringFunction {
    template<typename U, std::string(U::*)() const>
    struct matcher;

    template<typename U>
    static char helper(matcher<U, &U::toString> *);

    template<typename U>
    static int helper(...);

    enum { value = (sizeof(helper<T>()) == 1) };
};

template <bool>
struct ToStringWrapper {};

template<>
struct ToStringWrapper<true> {
    template<typename T>
    static std::string toString(const T & x) {
        return x.toString();
    }
};

template<>
struct ToStringWrapper<false> {
    template<typename T>
    static std::string toString(const T & x) {
        return std::string(typeid(x).name());
    }
};

}  /* namespace detail */

template<typename T>
std::string toString(const T & x) {
    return detail::ToStringWrapper<detail::HasToStringFunction<T>::value>::toString(x);
}

}  /* namespace StringUtils */

}  /* namespace akee */

#endif  /* _AKEE_UTILS_TOSTRING_H_ */
