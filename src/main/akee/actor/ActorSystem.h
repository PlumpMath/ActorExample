
#ifndef _AKEE_ACTOR_ACTORSYSTEM_H_
#define _AKEE_ACTOR_ACTORSYSTEM_H_

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

#include <string>

#include "akee/basic/stddef.h"
#include "akee/config/Config.h"
#include "akee/config/ConfigurationFactory.h"
#include "akee/actor/ActorRef.h"
#include "akee/actor/Props.h"
#include "akee/actor/IActorRefFactory.h"
#include "akee/actor/IDisposable.h"
#include "akee/actor/ActorSystemFactory.h"

namespace akee {

class ActorSystem : public IActorRefFactory, public IDisposable {
private:
    std::string name_;
    Config config_;

public:
    ActorSystem(const std::string & name) {
        initActorSystem(name, ConfigurationFactory::load());
    }

    ActorSystem(const std::string & name, const Config & withFallBack) {
        initActorSystem(name, withFallBack);
    }

private:
    void initActorSystem(const std::string & name, const Config & withFallBack) {
        name_ = name;
        config_ = withFallBack;
    }

protected:
    static ActorSystem * createAndStartSystem(const std::string & name, const Config & withFallBack);

public:
    static ActorSystem * create(const std::string & name) {
        return createAndStartSystem(name, ConfigurationFactory::load());
    }

    static ActorSystem * create(const std::string & name, const Config & config) {
        return createAndStartSystem(name, config);
    }

    static IActorRef * findActor(const Props & props, const std::string & name) {
        return nullptr;
    }

    std::string getName() const {
        return name_;
    }

    void setName(const std::string & name) {
        name_ = name;
    }

    int create() {
        return 0;
    }

    // Startup the actor systems
    int start() {
        return 0;
    }

    void shutdown() {
        //
    }
};

}  /* namespace akee */

#if 1

#ifdef DEF_ACTORSYSTEM_INLINE

#include "akee/actor/ActorSystemImpl.h"

namespace akee {

ActorSystem * ActorSystem::createAndStartSystem(const std::string & name, const Config & withFallBack) {
    ActorSystem * system = new ActorSystemImpl(name, withFallBack);
    if (system) {
        system->start();
    }
    return system;
}

}  /* namespace akee */

#endif  /* DEF_ACTORSYSTEM_INLINE */

#endif

#endif  /* _AKEE_ACTOR_ACTORSYSTEM_H_ */
