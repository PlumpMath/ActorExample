
#ifndef _AKEE_ACTOR_ACTORREF_H_
#define _AKEE_ACTOR_ACTORREF_H_

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

#include <string>
#include <iostream>

#include "akee/basic/stddef.h"
#include <akee/actor/ActorPath.h>
#include <akee/actor/IActorRef.h>
#include <akee/actor/IActorContext.h>
#include <akee/actor/ActorBase.h>

namespace akee {

class ActorRef;

class IActorRefScope {
private:
    bool isLocal_;

public:
    IActorRefScope() : isLocal_(false) {
    }

    IActorRefScope(bool isLocal) : isLocal_(isLocal) {
    }

    virtual bool isLocal() const { return isLocal_; }
};

class ILocalRef : public IActorRefScope {
public:
    ILocalRef() : IActorRefScope(true) {
    }

    ILocalRef(bool isLocal) : IActorRefScope(isLocal) {
    }

    bool isLocal() const { return true; }
};

class IRepointableRef : public IActorRefScope {
private:
    bool isStarted_;

public:
    IRepointableRef(bool isStarted, bool isLocal)
        : IActorRefScope(isLocal),
          isStarted_(isStarted) {
    }

    IRepointableRef(bool isStarted)
        : IActorRefScope(),
          isStarted_(isStarted) {
    }

    virtual bool isStarted() const { return isStarted_; }
};

class IActorRefProvider;

class MinimalActorRef {};

class Nobody : public MinimalActorRef {
public:
    static Nobody * instance_;

private:
    ActorPath * path_;

private:
    Nobody() : path_(NULL) {
        path_ = new RootActorPath("/Nobody");
    }

public:
    ~Nobody() { }

public:
    static void initNobody() {
        instance_ = new Nobody();
    }

    static Nobody * getInstance() {
        return instance_;
    }

    ActorPath * getPath() const { return path_; }
    IActorRefProvider * getProvider() const { return nullptr; }
};

class ActorRefs {
public:
    static Nobody * nobody_;
    static IActorRef * nosender_;

public:
    static void staticInit() {
        nobody_ = Nobody::getInstance();
        nosender_ = nullptr;
    }

    static Nobody * getNobody() {
        return nobody_;
    }

    static IActorRef * getNoSender() {
        return nosender_;
    }
};

class ITellable {
public:
    virtual void tell(void * func, const ActorRef & result) = 0;
};

class ActorRefBase : public IActorRef {
private:
    ActorPath * path_;

public:
    virtual ActorPath * getPath() const {
        return path_;
    }
};

class IActorRefProvider;

class InternalActorRefBase : public ActorRefBase, public IInternalActorRef {
private:
    IActorContext *     context_;
    IInternalActorRef * parent_;
    IActorRefProvider * provider_;

public:
    InternalActorRefBase() {}

    virtual IInternalActorRef * getParent() const { return parent_; }
    virtual IActorRefProvider * getProvider() const { return provider_; }

    virtual IActorContext * getContext() const {
        return context_;
    }
};

class ActorRef : public ActorRefBase,
                 public ITellable {
private:
    std::string name_;
    IActorContext * context_;

public:
    ActorRef() : ActorRefBase() {
        initActorRef("default");
    }

    ActorRef(const std::string & name) {
        initActorRef(name);
    }

    ActorRef(const ActorRef & src) {
        cloneActorRef(src);
    }

    ~ActorRef() {
    }

private:
    void initActorRef(const std::string & name) {
        name_ = name;
    }

protected:
    void cloneActorRef(const ActorRef & src) {
        this->name_ = src.name_;
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
