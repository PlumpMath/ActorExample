
#ifndef _AKEE_ACTOR_ACTORSYSTEMIMPL_H_
#define _AKEE_ACTOR_ACTORSYSTEMIMPL_H_

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

#include "akee/basic/stddef.h"

#include <string>

//#include <akee/actor/ActorSystem.h>

#include <akee/config/Config.h>
#include <akee/config/ConfigurationFactory.h>

namespace akee {

class ActorSystemImpl : public ActorSystem {
public:
	ActorSystemImpl(const std::string & name) : ActorSystem(name) {
		//
	}

	ActorSystemImpl(const std::string & name, const Config & config)
		: ActorSystem(name, config) {
		//
	}

	~ActorSystemImpl() {
	}

protected:
	ActorSystem * createSystemImpl(const std::string & name, const Config & config);
	ActorSystem * createAndStartSystemImpl(const std::string & name, const Config & config);
};

}  /* namespace akee */

#endif  /* _AKEE_ACTOR_ACTORSYSTEMIMPL_H_ */
