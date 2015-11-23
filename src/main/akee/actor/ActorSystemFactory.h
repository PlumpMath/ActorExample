
#ifndef _AKEE_ACTOR_ACTORSYSTEMFACTORY_H_
#define _AKEE_ACTOR_ACTORSYSTEMFACTORY_H_

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

#include <string>

#include <akee/actor/ActorSystem.h>
#include <akee/actor/ActorSystemImpl.h>

namespace akee {

class Config;

class ActorSystemFactory {
public:
    ActorSystemFactory() {
    }

    ~ActorSystemFactory() {
    }

    static ActorSystem * create(const std::string & name) {
        return createAndStartSystem(name, ConfigurationFactory::load());
    }

    static ActorSystem * create(const std::string & name, const Config & config) {
        return createAndStartSystem(name, config);
    }

protected:
    static ActorSystem * createAndStartSystem(const std::string & name, const Config & withFallBack) {
        ActorSystem * system = new ActorSystemImpl(name, withFallBack);
        if (system) {
            system->start();
        }
        return system;
    }
};

}  /* namespace akee */

#endif  /* _AKEE_ACTOR_ACTORSYSTEMFACTORY_H_ */
