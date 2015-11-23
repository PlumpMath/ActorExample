
#include <string>

#include "akee/actor/ActorSystemFactory.h"
#include "akee/config/Config.h"
#include "akee/actor/ActorSystem.h"
#include "akee/actor/ActorSystemImpl.h"

akee::ActorSystem * globalCreateAndStartSystem(const std::string & name, const akee::Config & withFallBack) {
    akee::ActorSystem * system = new akee::ActorSystemImpl(name, withFallBack);
    if (system) {
        system->start();
    }
    return system;
}

namespace akee {

ActorSystem * staticCreateAndStartSystem(const std::string & name, const Config & withFallBack) {
    ActorSystem * system = new ActorSystemImpl(name, withFallBack);
    if (system) {
        system->start();
    }
    return system;
}

}  /* namespace akee */
