
#ifndef _AKEE_SCHEDULER_IADVANCEDSCHEDULER_H_
#define _AKEE_SCHEDULER_IADVANCEDSCHEDULER_H_

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

#include "akee/scheduler/IActionScheduler.h"

namespace akee {

class IAdvancedScheduler : public IActionScheduler {
public:
    virtual IAdvancedScheduler * getAdvanced() const = 0;
};

}  /* namespace akee */

#endif  /* _AKEE_SCHEDULER_IADVANCEDSCHEDULER_H_ */
