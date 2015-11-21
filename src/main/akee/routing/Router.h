
#ifndef _AKEE_ROUTING_ROUTER_H_
#define _AKEE_ROUTING_ROUTER_H_

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

#include <string>

namespace akee {

class RouterConfig;

class Router {
protected:
    int numOfWorkers_;
    RouterConfig * routerConfig_;

public:
    Router() : numOfWorkers_(0) {
    }

    Router(int numOfWorkers) : numOfWorkers_(numOfWorkers) {
    }

    ~Router() {
    }

    RouterConfig * getRouterConfig() const {
        return routerConfig_;
    }
};

}  /* namespace akee */

#endif  /* _AKEE_ROUTING_ROUTER_H_ */
