
#ifndef _AKEE_ACTOR_IACTORCONTEXT_H_
#define _AKEE_ACTOR_IACTORCONTEXT_H_

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

#include <string>

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
    // IActorRefFactory
#if 0
    virtual IActorRef * actorOf(const Props & props, const std::string & name = "") const = 0;
    virtual ActorSelection * getActorSelection(const ActorPath & actorPath) const = 0;
    virtual ActorSelection * getActorSelection(const std::string & actorPath) const = 0;
#endif

    // IActorContext
    virtual Props * getProps() const = 0;
    virtual IActorRef * getSelf() const = 0;
    virtual IActorRef * getSender() const = 0;
    virtual IActorRef * getParent() const = 0;
    virtual IActorRef * getChild() const = 0;
    virtual ActorSystem * getSystem() const = 0;

    virtual void setProps(Props * props) const = 0;
    virtual void setSelf(IActorRef * self) const = 0;
    virtual void setSender(IActorRef * sender) const = 0;
    virtual void setParent(IActorRef * parent) const = 0;
    virtual void setChild(IActorRef * child) const = 0;
    virtual void setSystem(ActorSystem * system) const = 0;

    virtual IActorContext * create() = 0;
    virtual void stop(IActorRef * child) = 0;
    virtual void release() = 0;

#if 0
    virtual IActorRef * actorOf(const Props & props, const std::string & name = "") const {
        IActorRef * actorNew = ActorSystem::findActor(props, name);
        if (actorNew) {
            //
        }
        return actorNew;
    }
#endif
};

}  /* namespace akee */

#endif  /* _AKEE_ACTOR_IACTORCONTEXT_H_ */
