
#ifndef _AKEE_SCHEDULER_IACTIONSCHEDULER_H_
#define _AKEE_SCHEDULER_IACTIONSCHEDULER_H_

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

namespace akee {

class TimeSpan;
class Action;
class ICancelable;

class IActionScheduler {
public:
    virtual void ScheduleOnce(TimeSpan * delay, Action * action, ICancelable * cancelable) = 0;
    virtual void ScheduleOnce(TimeSpan * delay, Action * action) = 0;
    virtual void ScheduleRepeatedly(TimeSpan * initialDelay, TimeSpan * interval, Action * action, ICancelable * cancelable) = 0;
    virtual void ScheduleRepeatedly(TimeSpan * initialDelay, TimeSpan * interval, Action * action) = 0;
};

}  /* namespace akee */

#endif  /* _AKEE_SCHEDULER_IACTIONSCHEDULER_H_ */
