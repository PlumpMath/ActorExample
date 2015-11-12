
#ifndef _AKEE_ACTOR_IACTORCONTEXT_H_
#define _AKEE_ACTOR_IACTORCONTEXT_H_

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

#include "akee/basic/stddef.h"
#include <string>

#include "akee/actor/IActorRefFactory.h"

namespace akee {

class IActorRef;
class ActorSystem;

class IActorContext : public IActorRefFactory {
private:
    IActorRef * self_;
    IActorRef * sender_;
    ActorSystem * system_;

public:
    virtual IActorRef * getSelf() const { return self_; }
    virtual IActorRef * getSender() const { return sender_; }
    virtual ActorSystem * getSystem() const { return system_; }
};

}  /* namespace akee */

#endif  /* _AKEE_ACTOR_IACTORCONTEXT_H_ */
