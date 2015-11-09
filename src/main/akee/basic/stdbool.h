
#ifndef _AKEE_BASIC_STDBOOL_H_
#define _AKEE_BASIC_STDBOOL_H_

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

#if defined(_MSC_VER) && (_MSC_VER < 1700)
#include "akee/basic/msvc/stdbool.h"
#else
#include <stdbool.h>
#endif  /* _MSC_VER */

#endif  /* _AKEE_BASIC_STDBOOL_H_ */
