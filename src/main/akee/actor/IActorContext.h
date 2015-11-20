
#ifndef _AKEE_ACTOR_IACTORCONTEXT_H_
#define _AKEE_ACTOR_IACTORCONTEXT_H_

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

#include <string>

#if 0
#include "akee/actor/Props.h"
#include "akee/actor/IActorRef.h"
#include "akee/actor/ActorSystem.h"
#endif

#include "akee/actor/IActorRefFactory.h"

namespace akee {

class Props;
class IActorRef;
class ActorSystem;
class IActorRefFactory;
class ActorSystem;

class IActorContext : public IActorRefFactory {
#if 0
private:
    IActorRef * self_;
    IActorRef * sender_;
    ActorSystem * system_;
    IActorRef * parent_;
    IActorRef * child_;
#endif

public:
    virtual IActorRef * getProps() const = 0;
    virtual IActorRef * getSelf() const = 0;
    virtual IActorRef * getSender() const = 0;
    virtual ActorSystem * getSystem() const = 0;
    virtual IActorRef * getParent() const = 0;
    virtual IActorRef * getChild() const = 0;

#if 0
    virtual IActorRef * actorOf(const Props & props, const std::string & name = "") const {
        ActorRef * actorNew = ActorSystem::findActor(props, name);
        if (actorNew) {
            //
        }
        return actorNew;
    }
#endif

    virtual void stop(IActorRef * child) = 0;
};

}  /* namespace akee */

#endif  /* _AKEE_ACTOR_IACTORCONTEXT_H_ */
