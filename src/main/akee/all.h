
#ifndef _AKEE_ALL_H_
#define _AKEE_ALL_H_

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

#include <stdio.h>

#include "akee/basic/stddef.h"
#include "akee/basic/stdint.h"

AKEE_API
int only_test_for_api_export() {
    // Do nothing!!
    printf("Only test for api export.\n");
    return 0;
}

#endif  /* _AKEE_ALL_H_ */
