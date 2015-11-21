
#ifndef _AKEE_ACTOR_ICANTELL_H_
#define _AKEE_ACTOR_ICANTELL_H_

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

#include "akee/actor/MessageObject.h"

namespace akee {

class IActorRef;

class ICanTell {
public:
    virtual void tell(MessageObject message, IActorRef * sender) const = 0;
};

}  /* namespace akee */

#endif  /* _AKEE_ACTOR_ICANTELL_H_ */
