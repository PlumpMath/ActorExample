
#ifndef _AKEE_ACTOR_ACTORREF_H_
#define _AKEE_ACTOR_ACTORREF_H_

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

#include "akee/basic/stddef.h"

#include <string>
#include <iostream>

#include <akee/config/Config.h>
#include <akee/config/ConfigurationFactory.h>

#include <akee/actor/IActorRef.h>
#include <akee/actor/IActorContext.h>
#include <akee/actor/ActorBase.h>

namespace akee {

class ActorRef;

class ITellable {
public:
    virtual void tell(void * func, const ActorRef & result) = 0;
};

class ActorRef : public ActorBase,
                 public IActorRef,
                 public ITellable {
private:
    std::string name_;
    Config config_;
    IActorContext * context_;

public:
    ActorRef() {
        initActorRef("default", ConfigurationFactory::load());
    }

    ActorRef(const std::string & name) {
        initActorRef(name, ConfigurationFactory::load());
    }

    ActorRef(const std::string & name, const Config & config) {
        initActorRef(name, config);
    }

    ActorRef(const ActorRef & src) {
        cloneActorRef(src);
    }

    ~ActorRef() {
    }

private:
    void initActorRef(const std::string & name, const Config & config) {
        name_ = name;
        config_ = config;
    }

protected:
    ActorRef * createActorRef(const std::string & name, const Config & config);
    ActorRef * createAndStartActorRef(const std::string & name, const Config & config);

    void cloneActorRef(const ActorRef & src) {
        this->name_ = src.name_;
        this->config_ = src.config_;
    }

public:
    IActorRef * getSelf() const { return getContext()->getSelf(); }
    IActorRef * getSender() const { return getContext()->getSender(); }
    ActorSystem * getSystem() const { return getContext()->getSystem(); }
    IActorContext * getContext() const { return context_; }

    std::string getName() const {
        return name_;
    }

    void setName(const std::string & name) {
        name_ = name;
    }

    void tell(void * func, const ActorRef & result) const {
        std::cout << "ActorRef::tell();" << std::endl;
    }

    int start() {
        return 0;
    }
};

}  /* namespace akee */

#endif  /* _AKEE_ACTOR_ACTORREF_H_ */
