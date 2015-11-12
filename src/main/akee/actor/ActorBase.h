
#ifndef _AKEE_ACTOR_ACTORBASE_H_
#define _AKEE_ACTOR_ACTORBASE_H_

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

#include "akee/basic/stddef.h"
#include <string>

#include <akee/actor/IInternalActor.h>
#include <akee/actor/IActorContext.h>
#include <akee/config/Config.h>
#include <akee/config/ConfigurationFactory.h>

namespace akee {

class ActorSystem;
//class IActorContext;
class IActorRef;

class ActorBase : public IInternalActor {
private:
	std::string name_;
	Config config_;
    IActorContext * context_;

public:
	ActorBase() {
		initActor("default", ConfigurationFactory::load());
	}

	ActorBase(const std::string & name) {
		initActor(name, ConfigurationFactory::load());
	}

	ActorBase(const std::string & name, const Config & config) {
		initActor(name, config);
	}

	ActorBase(const ActorBase & src) {
		cloneActor(src);
	}

	~ActorBase() {
	}

private:
    void initActor(const std::string & name, const Config & config) {
        name_ = name;
        config_ = config;
    }

protected:
	//ActorBase * createActor(const std::string & name, const Config & config);
	//ActorBase * createAndStartActor(const std::string & name, const Config & config);

	void cloneActor(const ActorBase & src) {
		this->name_ = src.name_;
		this->config_ = src.config_;
	}

public:
    IActorRef * getSelf() const { return nullptr; }
    IActorRef * getSender() const { return nullptr; }
    ActorSystem * getSystem() const { return nullptr; }
    IActorContext * getContext() const { return context_; }

    // IInternalActor
    IActorContext * getActorContext() const {
        return this->getContext();
    };

	std::string getName() const {
		return name_;
	}

	void setName(const std::string & name) {
		name_ = name;
	}

	int start() {
		return 0;
	}
};

}  /* namespace akee */

#endif  /* _AKEE_ACTOR_ACTORBASE_H_ */
