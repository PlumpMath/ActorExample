

#include "akee/actor/Actor.h"
#include "akee/actor/ActorImpl.h"

namespace akee {

Actor * Actor::createActor(const std::string & name, const Config & config) {
	Actor * actor = new ActorImpl(name);
	return actor;
}

Actor * Actor::createAndStartActor(const std::string & name, const Config & config) {
	Actor * actor = new ActorImpl(name);
	if (actor) {
		actor->start();
	}
	return actor;
}

}  /* namespace akee */
