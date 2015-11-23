
#ifndef _AKEE_SCHEDULER_ITELLSCHEDULER_H_
#define _AKEE_SCHEDULER_ITELLSCHEDULER_H_

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

namespace akee {

class TimeSpan;
class ICanTell;
class MessageObject;
class IActorRef;
class ICancelable;

class ITellScheduler {
public:
    virtual void ScheduleTellOnce(TimeSpan * delay, ICanTell * receiver, MessageObject message, IActorRef * sender) = 0;
    virtual void ScheduleTellOnce(TimeSpan * delay, ICanTell * receiver, MessageObject message, IActorRef * sender, ICancelable * cancelable) = 0;
    virtual void ScheduleTellRepeatedly(TimeSpan * initialDelay, TimeSpan * interval, ICanTell * receiver, MessageObject * message, IActorRef * sender) = 0;
    virtual void ScheduleTellRepeatedly(TimeSpan * initialDelay, TimeSpan * interval, ICanTell * receiver, MessageObject * message, IActorRef * sender, ICancelable * cancelable) = 0;
};

}  /* namespace akee */

#endif  /* _AKEE_SCHEDULER_ITELLSCHEDULER_H_ */
