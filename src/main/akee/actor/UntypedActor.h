
#ifndef _AKEE_ACTOR_UNTYPEDACTOR_H_
#define _AKEE_ACTOR_UNTYPEDACTOR_H_

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

#include <string>

#include "akee/actor/Actor.h"

namespace akee {

class IActorRef;

class UntypedActor : public Actor {
private:
    //

public:
    UntypedActor() : Actor() {
    }

    UntypedActor(const std::string & path) : Actor(path) {
    }

    ~UntypedActor() {
    }
};

}  /* namespace akee */

#endif  /* _AKEE_ACTOR_UNTYPEDACTOR_H_ */
