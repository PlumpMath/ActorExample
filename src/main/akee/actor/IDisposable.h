
#ifndef _AKEE_ACTOR_IDISPOSABLE_H_
#define _AKEE_ACTOR_IDISPOSABLE_H_

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

namespace akee {

class IDisposable {
public:
    virtual void Dispose() = 0;
};

}  /* namespace akee */

#endif  /* _AKEE_ACTOR_IDISPOSABLE_H_ */
