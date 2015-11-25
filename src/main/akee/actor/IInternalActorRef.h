
#ifndef _AKEE_ACTOR_IINTERNALACTOR_H_
#define _AKEE_ACTOR_IINTERNALACTOR_H_

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

#include "akee/actor/IActorRef.h"
#include "akee/actor/IActorRefScope.h"

namespace akee {

class IActorRefProvider;
class ISystemMessage;

class IInternalActorRef : /* public IActorRef, */ public IActorRefScope {
public:
    virtual IInternalActorRef * getParent() const = 0;
    virtual IActorRefProvider * getProvider() const = 0;

    virtual bool isTerminated() const = 0;
    virtual IActorRef * getChild(const std::string & name) const = 0;

    virtual void resume() = 0;
    virtual void start() = 0;
    virtual void stop() = 0;
    virtual void restart() = 0;
    virtual void suspend() = 0;
    virtual void sendSystemMessage(const ISystemMessage * message, const IActorRef * sender = nullptr) = 0;
};

}  /* namespace akee */

#endif  /* _AKEE_ACTOR_IINTERNALACTOR_H_ */
