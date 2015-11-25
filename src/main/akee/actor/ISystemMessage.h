
#ifndef _AKEE_ACTOR_ISYSTEMMESSAGE_H_
#define _AKEE_ACTOR_ISYSTEMMESSAGE_H_

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

#include "akee/actor/INoSerializationVerificationNeeded.h"

namespace akee {

class IActorRef;

class ISystemMessage : public INoSerializationVerificationNeeded {
public:
    struct LocalMessage {
        enum {
            Terminate
        };
    };

    virtual int getType() const = 0;
    virtual void setType(int type) = 0;
};

class DeathWatchNotification : public ISystemMessage {
private:
    int type_;
    IActorRef * actor_;

private:
    void setActor(IActorRef * actor) {
        actor_ = actor;
    }

public:
    DeathWatchNotification(IActorRef * actor) {
        actor_ = actor;
    }

    int getType() const { return type_; }
    void setType(int type) { type_ = type; }

    IActorRef * getActor() const { return actor_; }
};

}  /* namespace akee */

#endif  /* _AKEE_ACTOR_ISYSTEMMESSAGE_H_ */
