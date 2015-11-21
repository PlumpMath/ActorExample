
#ifndef _AKEE_ROUTING_ROUTERCONFIG_H_
#define _AKEE_ROUTING_ROUTERCONFIG_H_

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

#include <string>

namespace akee {

class RouterConfig {
protected:
    int numOfWorkers_;

public:
    RouterConfig() : numOfWorkers_(0) {
    }

    RouterConfig(int numOfWorkers) : numOfWorkers_(numOfWorkers) {
    }

    ~RouterConfig() {
    }
};

}  /* namespace akee */

#endif  /* _AKEE_ROUTING_ROUTERCONFIG_H_ */
