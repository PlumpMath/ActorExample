
#ifndef _AKEE_ACTOR_ACTORBASE_H_
#define _AKEE_ACTOR_ACTORBASE_H_

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

#include <string>
#include <iostream>

#include "akee/basic/stddef.h"
#include "akee/actor/IInternalActorRef.h"
#include "akee/actor/IActorContext.h"
#include "akee/actor/IActorRef.h"

namespace akee {

class ActorSystem;

class IInternalActor {
public:
    virtual IActorContext * getActorContext() const = 0;
};

class ActorBase : public IInternalActor {
protected:
    std::string name_;
    IActorRef * clearedSelf_;
    IActorContext * context_;

public:
    ActorBase() : clearedSelf_(nullptr), context_(nullptr) {
        initActor("default");
    }

    ActorBase(const std::string & name)
     : clearedSelf_(nullptr), context_(nullptr) {
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

    bool hasBeenCleared() const {
        return (clearedSelf_ != nullptr);
    }

protected:
    void cloneActor(const ActorBase & src) {
        this->name_ = src.name_;
    }

public:
    // For IActorContext
    Props * getProps() const { return getContext()->getProps(); }
    IActorRef * getSelf() const {
        return (hasBeenCleared() ? clearedSelf_ : getContext()->getSelf());
    }
    IActorRef * getSender() const { return getContext()->getSender(); }
    IActorRef * getParent() const { return getContext()->getParent(); }
    IActorRef * getChild() const { return getContext()->getChild(); }
    ActorSystem * getSystem() const { return getContext()->getSystem(); }
    
    // For call IActorContext
    IActorContext * getContext() const { return context_; }
    void setContext(IActorContext * context) { context_ = context; }

    // IInternalActor
    virtual IActorContext * getActorContext() const {
        return this->getContext();
    }

    void clear(IActorRef * self) {
        clearedSelf_ = self;
    }

    void unclear() {
        clearedSelf_ = nullptr;
    }

    std::string getName() const {
        return name_;
    }

    void setName(const std::string & name) {
        name_ = name;
    }

    void Unhandle(MessageObject message) {
        std::cout << ">>> Unhandle Message <<<" << std::endl;
        std::cout << "Message Object: " << message << "." << std::endl;
        std::cout << ">>> ---------------- <<<" << std::endl;
    }
};

}  /* namespace akee */

#endif  /* _AKEE_ACTOR_ACTORBASE_H_ */
