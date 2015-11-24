
#ifndef _AKEE_ACTOR_ACTORSYSTEMFACTORY_H_
#define _AKEE_ACTOR_ACTORSYSTEMFACTORY_H_

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

#include <string>

#include "akee/basic/stddef.h"
#include "akee/config/ConfigurationFactory.h"

namespace akee {

class Config;
class ActorSystem;

}

akee::ActorSystem * globalCreateAndStartSystem(const std::string & name, const akee::Config & withFallBack);

namespace akee {

ActorSystem * staticCreateAndStartSystem(const std::string & name, const Config & withFallBack);

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
#if 1
        return staticCreateAndStartSystem(name, withFallBack);
#elif 1
        return globalCreateAndStartSystem(name, withFallBack);
#else
        ActorSystem * system = new ActorSystemImpl(name, withFallBack);
        if (system) {
            system->start();
        }
        return system;
#endif
    }
};

}  /* namespace akee */

#endif  /* _AKEE_ACTOR_ACTORSYSTEMFACTORY_H_ */
