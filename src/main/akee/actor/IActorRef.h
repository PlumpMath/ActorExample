
#ifndef _AKEE_ACTOR_IACTORREF_H_
#define _AKEE_ACTOR_IACTORREF_H_

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

#include "akee/actor/ICanTell.h"
#include "akee/actor/ISurrogated.h"

namespace akee {

class ActorPath;

class IActorRef : public ICanTell, public ISurrogated {
public:
    virtual ActorPath * getPath() const = 0;
};

}  /* namespace akee */

#endif  /* _AKEE_ACTOR_IACTORREF_H_ */
