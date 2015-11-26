
#ifndef _AKEE_UTILS_MINMAX_H_
#define _AKEE_UTILS_MINMAX_H_

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

#define NOMINMAX

namespace akee {

#define AKEE_MIN(x, y)  ((x) <= (y) ? (x) : (y))
#define AKEE_MAX(x, y)  ((x) >= (y) ? (x) : (y))

namespace utils {

template <typename _Ty>
_Ty (min)(const _Ty & x, const _Ty & y) {
    return (x <= y) ? x : y;
}

template <typename _Ty>
_Ty min2(const _Ty x, const _Ty y) {
    return (x <= y) ? x : y;
}

template <typename _Ty>
_Ty (max)(const _Ty & x, const _Ty & y) {
    return (x >= y) ? x : y;
}

template <typename _Ty>
_Ty max2(const _Ty x, const _Ty y) {
    return (x >= y) ? x : y;
}

}  /* namespace utils */

}  /* namespace akee */

#endif  /* _AKEE_UTILS_MINMAX_H_ */
