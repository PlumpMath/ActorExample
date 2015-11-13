
#ifndef _AKEE_DISPATCH_MESSAGE_H_
#define _AKEE_DISPATCH_MESSAGE_H_

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

#include "akee/basic/stddef.h"
#include <string>

namespace akee {

class ActorPath;

struct IMessage {
    virtual ActorPath * getPath() const = 0;
};

class Message : public IMessage {
    //
};

}  /* namespace akee */

#endif  /* _AKEE_DISPATCH_MESSAGE_H_ */
