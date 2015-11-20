
#ifndef _AKEE_ACTOR_IACTORREFFACTORY_H_
#define _AKEE_ACTOR_IACTORREFFACTORY_H_

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

#include <string>

//#include "akee/actor/IActorRef.h"
//#include "akee/actor/ActorPath.h"
//#include "akee/actor/Props.h"

namespace akee {

class IActorRef;
class Props;
class ActorPath;
class ActorSelection;

class IActorRefFactory {
public:
    virtual IActorRef * actorOf(const Props & props, const std::string & name = "") const = 0;
    virtual ActorSelection * getActorSelection(const ActorPath & actorPath) const = 0;;
    virtual ActorSelection * getActorSelection(const std::string & actorPath) const = 0;;
};

}  /* namespace akee */

#endif  /* _AKEE_ACTOR_IACTORREFFACTORY_H_ */
