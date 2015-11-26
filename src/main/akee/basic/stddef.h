
#ifndef _AKEE_BASIC_STDDEF_H_
#define _AKEE_BASIC_STDDEF_H_

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

#include "akee/basic/stdint.h"

#if defined(AKEE_USE_SHARED)
#define AKEE_API        extern "C" _declspec(dllimport)
#elif defined(AKEE_SHARED_DLL)
#define AKEE_API        extern "C" _declspec(dllexport)
#else
// AKEE_USE_STATIC, AKEE_STATIC_LIB
#define AKEE_API        extern "C" static
#endif

#ifndef AKEE_CACHE_LINE_SIZE
#define AKEE_CACHE_LINE_SIZE    64
#endif

#endif  /* _AKEE_BASIC_STDDEF_H_ */
