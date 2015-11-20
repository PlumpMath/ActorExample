
#ifndef _AKEE_ACTOR_ACTORPATH_H_
#define _AKEE_ACTOR_ACTORPATH_H_

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

#include <string>

namespace akee {

class ActorPath {
private:
    std::string path_;

public:
    ActorPath(std::string path) {
        path_ = path;
    }

    ~ActorPath() {
    }
};

}  /* namespace akee */

#endif  /* _AKEE_ACTOR_ACTORPATH_H_ */
