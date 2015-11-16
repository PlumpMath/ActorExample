
#ifndef _AKEE_ACTOR_IACTORREF_H_
#define _AKEE_ACTOR_IACTORREF_H_

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

#include "akee/basic/stddef.h"
#include <string>

namespace akee {

class ActorPath {
private:
    std::string path_;

public:
    ActorPath(std::string path) {
        path_ = path;
    }
};

struct IActorRef {
    virtual ActorPath * getPath() const = 0;
};

class RootActorPath : public ActorPath {
public:
    RootActorPath(std::string path) : ActorPath(path) {
    }
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
    IActorRefProvider * getProvider() const { return 0;  }
};

class ActorRefs {
public:
    static Nobody * nobody_;
    static IActorRef * nosender_;

public:
    static void initActorRefs() {
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

}  /* namespace akee */

#endif  /* _AKEE_ACTOR_IACTORREF_H_ */
