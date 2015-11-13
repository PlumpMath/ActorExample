
#ifndef _AKEE_DISPATCH_MAILBOX_H_
#define _AKEE_DISPATCH_MAILBOX_H_

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

#include "akee/basic/stddef.h"
#include <string>

namespace akee {

class ActorPath;

struct IDisposable {
    virtual void Dispose() = 0;
};

class Mailbox : public IDisposable {
private:
    std::string name_;

public:
    Mailbox() {
        initMailbox("default");
    }

    Mailbox(const std::string & name) {
        initMailbox(name);
    }

    Mailbox(const Mailbox & src) {
        this->name_ = src.name_;
    }

private:
    void initMailbox(const std::string & name) {
        name_ = name;
    }

public:
    // Interface IDisposable
    void Dispose() { /* TODO: */ }
};

}  /* namespace akee */

#endif  /* _AKEE_DISPATCH_MAILBOX_H_ */
