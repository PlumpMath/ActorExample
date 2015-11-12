
#ifndef _AKEE_ACTOR_IACTORREFFACTORY_H_
#define _AKEE_ACTOR_IACTORREFFACTORY_H_

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

#include "akee/basic/stddef.h"
#include <string>

namespace akee {

class IActorRef;
class Props;
class ActorSelection;
class ActorPath;

struct IActorRefFactory {
    virtual IActorRef * actorOf(const Props & props, const std::string & name = "") = 0;
    virtual ActorSelection * getActorSelection(const ActorPath & actorPath) = 0;;
    virtual ActorSelection * getActorSelection(const std::string & actorPath) = 0;;
};

}  /* namespace akee */

#endif  /* _AKEE_ACTOR_IACTORREFFACTORY_H_ */
