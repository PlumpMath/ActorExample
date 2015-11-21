
#ifndef _AKEE_ROUTING_ROUNDROBINROUTER_H_
#define _AKEE_ROUTING_ROUNDROBINROUTER_H_

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

#include <string>

#include "akee/routing/Router.h"

namespace akee {

class RoundRobinRouter : public Router {
private:
    //

public:
    RoundRobinRouter() : Router() {
    }

    RoundRobinRouter(int numOfWorkers) : Router(numOfWorkers) {
    }

    ~RoundRobinRouter() {
    }
};

}  /* namespace akee */

#endif  /* _AKEE_ROUTING_ROUNDROBINROUTER_H_ */
