
#ifndef _AKEE_UTILS_ROUNDTO_H_
#define _AKEE_UTILS_ROUNDTO_H_

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

#include "akee/basic/stdsize.h"

namespace akee {

namespace utils {

struct false_type {
    typedef false_type type;
    enum { value = 0 };
};

struct true_type {
    typedef true_type type;
    enum { value = 1 };
};

template<bool condition, class T, class U>
struct condition_if {
    typedef U type;
};

template <class T, class U>
struct condition_if<true, T, U> {
    typedef T type;
};

template<bool condition>
struct boolean_if {
    typedef typename condition_if<condition, true_type, false_type>::type type;
    enum { value = type::value };
};

template <int N>
struct is_pow_of_2 {
    enum { value = boolean_if<(N && ((N & (N - 1)) == 0))>::value };
};

template <>
struct is_pow_of_2<0> {
    enum { value = 1 };
};

#define ROUND_UP_TO_POW2_DEF(N) \
template <>                     \
struct round_up_to_pow2<(N)> {  \
    enum { value = (N) };       \
};

template <int N>
struct round_up_to_pow2 {
    enum { value = (is_pow_of_2<N>::value == 1) ? N : round_up_to_pow2<N + 1>::value };
};

ROUND_UP_TO_POW2_DEF(1 << 0)
ROUND_UP_TO_POW2_DEF(1 << 1)
ROUND_UP_TO_POW2_DEF(1 << 2)
ROUND_UP_TO_POW2_DEF(1 << 3)
ROUND_UP_TO_POW2_DEF(1 << 4)
ROUND_UP_TO_POW2_DEF(1 << 5)
ROUND_UP_TO_POW2_DEF(1 << 6)
ROUND_UP_TO_POW2_DEF(1 << 7)
ROUND_UP_TO_POW2_DEF(1 << 8)
ROUND_UP_TO_POW2_DEF(1 << 9)
ROUND_UP_TO_POW2_DEF(1 << 10)
ROUND_UP_TO_POW2_DEF(1 << 11)
ROUND_UP_TO_POW2_DEF(1 << 12)
ROUND_UP_TO_POW2_DEF(1 << 13)
ROUND_UP_TO_POW2_DEF(1 << 14)
ROUND_UP_TO_POW2_DEF(1 << 15)
ROUND_UP_TO_POW2_DEF(1 << 16)
ROUND_UP_TO_POW2_DEF(1 << 17)
ROUND_UP_TO_POW2_DEF(1 << 18)
ROUND_UP_TO_POW2_DEF(1 << 19)
ROUND_UP_TO_POW2_DEF(1 << 20)
ROUND_UP_TO_POW2_DEF(1 << 21)
ROUND_UP_TO_POW2_DEF(1 << 22)
ROUND_UP_TO_POW2_DEF(1 << 23)
ROUND_UP_TO_POW2_DEF(1 << 24)
ROUND_UP_TO_POW2_DEF(1 << 25)
ROUND_UP_TO_POW2_DEF(1 << 26)
ROUND_UP_TO_POW2_DEF(1 << 27)
ROUND_UP_TO_POW2_DEF(1 << 28)
ROUND_UP_TO_POW2_DEF(1 << 29)
ROUND_UP_TO_POW2_DEF(1 << 30)
ROUND_UP_TO_POW2_DEF(1 << 31)

#if defined(_WIN64)
template <>
struct round_up_to_pow2<18446744073709551615ULL> {
    enum { value = 0 };
};
#else
template <>
struct round_up_to_pow2<4294967295UL> {
    enum { value = 0 };
};
#endif

#undef ROUND_UP_TO_POW2_DEF

}  /* namespace utils */

}  /* namespace akee */

#endif  /* _AKEE_UTILS_ROUNDTO_H_ */
