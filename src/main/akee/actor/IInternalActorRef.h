
#ifndef _AKEE_ACTOR_IINTERNALACTOR_H_
#define _AKEE_ACTOR_IINTERNALACTOR_H_

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

namespace akee {

class IActorContext;

class IInternalActorRef {
public:
    virtual IActorContext * getContext() const = 0;
};

}  /* namespace akee */

#endif  /* _AKEE_ACTOR_IINTERNALACTOR_H_ */
