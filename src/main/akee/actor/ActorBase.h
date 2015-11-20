
#ifndef _AKEE_ACTOR_ACTORBASE_H_
#define _AKEE_ACTOR_ACTORBASE_H_

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

#include "akee/basic/stddef.h"
#include <string>

#include <akee/actor/IInternalActorRef.h>
#include <akee/actor/IActorContext.h>
#include <akee/actor/IActorRef.h>

namespace akee {

class ActorSystem;

class IInternalActor {
public:
    virtual IActorContext * getActorContext() const = 0;
};

class ActorBase : public IInternalActor {
private:
    std::string name_;
    IActorContext * context_;

public:
    ActorBase() {
        initActor("default");
    }

    ActorBase(const std::string & name) {
        initActor(name);
    }

    ActorBase(const ActorBase & src) {
        cloneActor(src);
    }

    ~ActorBase() {
    }

private:
    void initActor(const std::string & name) {
        name_ = name;
    }

protected:
    void cloneActor(const ActorBase & src) {
        this->name_ = src.name_;
    }

public:
    // IActorContext
    IActorRef * getSelf() const { return getContext()->getSelf(); }
    IActorRef * getSender() const { return getContext()->getSender(); }
    ActorSystem * getSystem() const { return getContext()->getSystem(); }
    
    IActorContext * getContext() const { return context_; }

    // IInternalActor
    virtual IActorContext * getActorContext() const {
        return this->getContext();
    };

    std::string getName() const {
        return name_;
    }

    void setName(const std::string & name) {
        name_ = name;
    }
};

}  /* namespace akee */

#endif  /* _AKEE_ACTOR_ACTORBASE_H_ */
