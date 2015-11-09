
#ifndef _AKEE_BASIC_INTTYPES_H_
#define _AKEE_BASIC_INTTYPES_H_

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

#if defined(_MSC_VER) && (_MSC_VER < 1700)
#include "akee/basic/msvc/inttypes.h"
#else
#include <inttypes.h>
#endif  /* _MSC_VER */

#endif  /* _AKEE_INTTYPES_H_ */
