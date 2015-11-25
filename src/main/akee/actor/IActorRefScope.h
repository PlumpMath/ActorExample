
#ifndef _AKEE_ACTOR_IACTORREFSCOPE_H_
#define _AKEE_ACTOR_IACTORREFSCOPE_H_

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

namespace akee {

class IActorRefScope {
public:
    virtual bool isLocal() const = 0;
};

}  /* namespace akee */

#endif  /* _AKEE_ACTOR_IACTORREFSCOPE_H_ */
