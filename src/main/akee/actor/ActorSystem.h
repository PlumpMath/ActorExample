
#ifndef _AKEE_ACTOR_ACTORSYSTEM_H_
#define _AKEE_ACTOR_ACTORSYSTEM_H_

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

#include "akee/basic/stddef.h"

#include <string>

using namespace std;

namespace akee {

class Actor {
private:
	std::string actorName_;

public:
	Actor(const std::string &actorName) {
		actorName_ = actorName;
	}

	std::string getName() const {
		return actorName_;
	}

	void setName(const std::string & actorName) {
		actorName_ = actorName;
	}
};

class ActorSystem {
private:
	std::string actorName_;

public:
	static Actor create(const std::string & actorName) {
		Actor actor(actorName);
		return actor;
	}
};

}  /* namespace akee */

#endif  /* _AKEE_ACTOR_ACTORSYSTEM_H_ */