
#ifndef _AKEE_DISPATCH_IMESSAGE_H_
#define _AKEE_DISPATCH_IMESSAGE_H_

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

#include "akee/basic/stddef.h"
#include <string>

namespace akee {

class ActorPath;

typedef uint32_t message_type;

class IMessage {
private:
    message_type type_;
    void * object_;

public:
    virtual message_type getType() const {
        return type_;
    }

    virtual void * getObject() const {
        return object_;
    }

    virtual ActorPath * getPath() const = 0;
};

}  /* namespace akee */

#endif  /* _AKEE_DISPATCH_IMESSAGE_H_ */
