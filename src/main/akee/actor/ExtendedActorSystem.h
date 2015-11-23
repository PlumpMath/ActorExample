
#ifndef _AKEE_ACTOR_EXTENDEDACTORSYSTEM_H_
#define _AKEE_ACTOR_EXTENDEDACTORSYSTEM_H_

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

#include <string>

#include "akee/actor/ActorSystem.h"

namespace akee {

class IActorRefProvider;
class IInternalActorRef;
class IActorRef;
class Props;

class ExtendedActorSystem : public ActorSystem {
public:
public:
    ExtendedActorSystem(const std::string & name) : ActorSystem(name) {
    }

    ExtendedActorSystem(const std::string & name, const Config & withFallBack)
     : ActorSystem(name, withFallBack) {
    }

public:
    virtual IActorRefProvider * getProvider() const = 0;
    virtual IInternalActorRef * getGuardian() const = 0;
    virtual IInternalActorRef * getSystemGuardian() const = 0;

    virtual IActorRef * systemActorOf(const Props * props, const std::string & name) = 0;
};

}  /* namespace akee */

#endif  /* _AKEE_ACTOR_EXTENDEDACTORSYSTEM_H_ */
