
#ifndef _AKEE_ACTOR_ACTORIMPL_H_
#define _AKEE_ACTOR_ACTORIMPL_H_

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

#include "akee/basic/stddef.h"

#include <string>

#include "akee/actor/Actor.h"

#include "akee/config/Config.h"
#include "akee/config/ConfigurationFactory.h"

namespace akee {

class ActorImpl : public Actor {
public:
	ActorImpl() : Actor() {

	}

	ActorImpl(const std::string & name) : Actor(name) {
		//
	}

	ActorImpl(const std::string & name, const Config & config)
		: Actor(name, config) {
		//
	}

	~ActorImpl() {
	}

protected:
	Actor * createActorImpl(const std::string & name, const Config & config);
	Actor * createAndStartActorImpl(const std::string & name, const Config & config);
};

extern Actor * static_createActorImpl(const std::string & name, const Config & config);

}  /* namespace akee */

#endif  /* _AKEE_ACTOR_ACTORIMPL_H_ */
