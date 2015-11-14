
#include "akee/actor/ActorImpl.h"

namespace akee {

Actor * ActorImpl::createActorImpl(const std::string & name, const Config & config) {
    Actor * actor = new ActorImpl(name, config);
    return actor;
}

Actor * ActorImpl::createAndStartActorImpl(const std::string & name, const Config & config) {
    Actor * actor = new ActorImpl(name, config);
    if (actor) {
        actor->start();
    }
    return actor;
}

}  /* namespace akee */
