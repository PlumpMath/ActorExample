
#ifndef _AKEE_ACTOR_ACTORSYSTEM_IPP_
#define _AKEE_ACTOR_ACTORSYSTEM_IPP_

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

#include <string>

#include "akee/actor/ActorSystem.h"
#include "akee/actor/ActorSystemImpl.h"

namespace akee {

class Config;

ActorSystem * ActorSystem::createAndStartSystem(const std::string & name, const Config & withFallBack) {
    ActorSystem * system = new ActorSystemImpl(name, withFallBack);
    if (system) {
        system->start();
    }
    return system;
}

}  /* namespace akee */

#endif  /* _AKEE_ACTOR_ACTORSYSTEM_IPP_ */
