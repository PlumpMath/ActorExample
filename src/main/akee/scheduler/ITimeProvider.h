
#ifndef _AKEE_SCHEDULER_ITIMEPROVIDER_H_
#define _AKEE_SCHEDULER_ITIMEPROVIDER_H_

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

#include "akee/basic/stddef.h"

namespace akee {

class ITimeProvider {
public:
    virtual uint64_t now() const = 0;
    virtual uint64_t MonotonicClock() const = 0;
    virtual uint64_t HighResMonotonicClock() const = 0;
};

}  /* namespace akee */

#endif  /* _AKEE_SCHEDULER_ITIMEPROVIDER_H_ */
