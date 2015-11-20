
#ifndef _AKEE_ACTOR_PROPS_H_
#define _AKEE_ACTOR_PROPS_H_

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

#include <string>

#include <akee/actor/Deploy.h>

namespace akee {

class Props {
private:
    std::string name_;
    Deploy * deploy_;
    uint32_t inputType_;
    uint32_t outputType_;

public:
    static bool staticInited;
    static Deploy * defaultDeploy;

protected:
    Props() : Props(*defaultDeploy, 0) {
    }

    Props(const Props & src) {
        copyProps(src);
    }

public:
    Props(const Deploy & deploy, uint32_t inputType) {
        *deploy_ = deploy;
        inputType_ = inputType;
    }

    ~Props() {
        if (deploy_ && deploy_ != defaultDeploy) {
            deploy_->destroy();
        }
    }

    static void staticInit() {
        if (!staticInited) {
            defaultDeploy = new Deploy();
            staticInited = true;
        }
    }

    static void staticFree() {
        if (staticInited) {
            if (defaultDeploy) {
                delete defaultDeploy;
            }
            staticInited = false;
        }
    }

    std::string getName() const {
        return name_;
    }

    void setName(const std::string & name) {
        name_ = name;
    }

protected:
    void copyProps(const Props & src) {
        this->name_ = src.name_;
        this->deploy_ = src.deploy_;
        this->inputType_ = src.inputType_;
        this->outputType_ = src.outputType_;
    }

private:
    //
};

}  /* namespace akee */

#endif  /* _AKEE_ACTOR_PROPS_H_ */
