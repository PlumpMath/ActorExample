
#ifndef _AKEE_ACTOR_IINTERNALACTOR_H_
#define _AKEE_ACTOR_IINTERNALACTOR_H_

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

#include "akee/basic/stddef.h"

namespace akee {

class IActorContext;

struct IInternalActor {
    virtual IActorContext * getActorContext() const = 0;
};

}  /* namespace akee */

#endif  /* _AKEE_ACTOR_IINTERNALACTOR_H_ */
