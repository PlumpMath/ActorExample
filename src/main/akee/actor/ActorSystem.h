
#ifndef _AKEE_ACTOR_ACTORSYSTEM_H_
#define _AKEE_ACTOR_ACTORSYSTEM_H_

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

#include "akee/basic/stddef.h"
#include <string>

#include "akee/config/Config.h"
#include "akee/config/ConfigurationFactory.h"

namespace akee {

class ActorSystem {
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

	std::string getName() const {
		return name_;
	}

	void setName(const std::string & name) {
		name_ = name;
	}

	// Startup the actor systems
	int start() {
		return 0;
	}
};

}  /* namespace akee */

 AKEE_API int only_test_for_api_export() {
	// Do nothing!!
    printf("Only test for api export.\n");
	return 0;
}

#ifndef DEF_ACTORSYSTEM_NOINLINE

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

#endif

#endif  /* _AKEE_ACTOR_ACTORSYSTEM_H_ */
