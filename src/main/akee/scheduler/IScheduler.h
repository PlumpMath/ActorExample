
#ifndef _AKEE_SCHEDULER_ISCHEDULER_H_
#define _AKEE_SCHEDULER_ISCHEDULER_H_

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

#include "akee/scheduler/ITellScheduler.h"
#include "akee/scheduler/ITimeProvider.h"

namespace akee {

class IAdvancedScheduler;

class IScheduler : public ITellScheduler, public ITimeProvider {
public:
    virtual IAdvancedScheduler * getAdvanced() const = 0;
};

}  /* namespace akee */

#endif  /* _AKEE_SCHEDULER_ISCHEDULER_H_ */
