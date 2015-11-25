
#ifndef _AKEE_ACTOR_ISURROGATED_H_
#define _AKEE_ACTOR_ISURROGATED_H_

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

namespace akee {

class ActorSystem;

class ISurrogated {
public:
    virtual ISurrogated * toSurrogate(const ActorSystem * system) = 0;
};

}  /* namespace akee */

#endif  /* _AKEE_ACTOR_ISURROGATED_H_ */
