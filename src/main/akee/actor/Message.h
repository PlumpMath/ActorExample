
#ifndef _AKEE_ACTOR_MESSAGE_H_
#define _AKEE_ACTOR_MESSAGE_H_

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

#include <string>

#include "akee/basic/stddef.h"
#include "akee/actor/MessageBase.h"

namespace akee {

class ActorPath;

class Message : public MessageBase {
private:
    //

public:
    Message() : MessageBase() {
        //
    }

    ~Message() { }
};

}  /* namespace akee */

#endif  /* _AKEE_ACTOR_MESSAGE_H_ */
