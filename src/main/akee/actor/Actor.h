
#ifndef _AKEE_ACTOR_ACTOR_H_
#define _AKEE_ACTOR_ACTOR_H_

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

#include "akee/basic/stddef.h"
#include <string>

#include <akee/config/Config.h>
#include <akee/config/ConfigurationFactory.h>

#include <akee/actor/IActorContext.h>
#include <akee/actor/ActorBase.h>

namespace akee {

class Actor : public ActorBase {
private:
    //

public:
    Actor() : ActorBase() {
    }

    Actor(const std::string & name) : ActorBase(name) {
    }

    Actor(const Actor & src) {
        cloneActor(src);
    }

    ~Actor() {
    }

private:
    void initActor(const std::string & name) {
        this->name_ = name;
    }

protected:
    Actor * createActor(const std::string & name, const Config & config);
    Actor * createAndStartActor(const std::string & name, const Config & config);

    void cloneActor(const Actor & src) {
        this->name_ = src.name_;
    }

public:
    std::string getName() const {
        return this->name_;
    }

    void setName(const std::string & name) {
        this->name_ = name;
    }

    int start() {
        return 0;
    }
};

}  /* namespace akee */

#endif  /* _AKEE_ACTOR_ACTOR_H_ */
