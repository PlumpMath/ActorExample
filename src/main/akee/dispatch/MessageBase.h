
#ifndef _AKEE_DISPATCH_MESSAGEBASE_H_
#define _AKEE_DISPATCH_MESSAGEBASE_H_

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

#include "akee/basic/stddef.h"
#include <string>

#include "akee/actor/ActorRef.h"

namespace akee {

enum {
    ACTOR_TYPE_UNKNOWN = 0,
    ACTOR_TYPE_START = 0,
    ACTOR_TYPE_PARALLEL_PI,
    ACTOR_TYPE_LAST
};

typedef uint32_t message_type;

enum  {
    UNKNOWN_MESSAGE = (message_type)(-1)
};

class MessageBase {
private:
    message_type type_;
    void * object_;

    ActorRef * sender_;
    ActorRef * receiver_;

public:
    MessageBase() : type_(UNKNOWN_MESSAGE),
        object_(nullptr),
        sender_(nullptr),
        receiver_(nullptr) {
    }

    ~MessageBase() { }

    message_type getType() const {
        return type_;
    }

    void * getObject() const {
        return object_;
    }

    ActorRef * getSender() const {
        return sender_;
    }

    ActorRef * getReceiver() const {
        return receiver_;
    }
};

}  /* namespace akee */

#endif  /* _AKEE_DISPATCH_MESSAGEBASE_H_ */
