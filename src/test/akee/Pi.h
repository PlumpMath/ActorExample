
#ifndef _AKEE_TEST_PI_H_
#define _AKEE_TEST_PI_H_

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

#include <akee/basic/stddef.h>
#include <akee/basic/stdint.h>

//#define AKEE_USE_STATICLIB
#include <akee/all.h>
#include <akee/actor/ActorSystem.h>
#include <akee/actor/ActorBase.h>
#include <akee/actor/Actor.h>
#include <akee/actor/ActorRef.h>
#include <akee/dispatch/Message.h>

using namespace akee;

class Calulate {
    //
};

class Work {
private:
    int start_;
    int numOfElements_;

public:
    Work(int start, int numOfElements) {
        start_ = start;
        numOfElements_ = numOfElements;
    }

    int getStart() const {
        return start_;
    }

    int getNumOfElements() const {
        return numOfElements_;
    }
};

class Result {
private:
    double value_;

public:
    Result(double value) {
        value_ = value;
    }

    double getValue() const {
        return value_;
    }
};

class PiApproximation {
private:
    double pi_;
    double duration_;

public:
    PiApproximation(double pi, double duration) {
        pi_ = pi;
        duration_ = duration;
    }

    double getPi() const {
        return pi_;
    }

    double getDuration() const {
        return duration_;
    }
};

enum {
    ACTOR_TYPE_UNKNOWN = (unsigned)(-1),
    ACTOR_TYPE_START = 0,
    ACTOR_TYPE_PARALLEL_PI,
    ACTOR_TYPE_LAST
};

static
double calulatePiFor(int start, int numOfElements) {
    double acc = 0.0;
    for (int i = start * numOfElements; i <= ((start + 1) * numOfElements - 1); ++i) {
        acc += 4.0 * (1 - (i % 2) * 2) / (2 * i + 1);
    }
    return acc;
}

class UntypedActor : public akee::Actor {
private:
    // 
public:
    ActorRef & getSender() const {
        //
    }

    ActorRef & getSelf() const {
        //
    }
};

class Worker : public UntypedActor {
public:
    void onReceive(IMessage * message) {
        message_type msgType = message->getType();
        if (msgType == ACTOR_TYPE_PARALLEL_PI) {
            //Work * work = dynamic_cast<Work *>(message->getObject());
            Work * work = reinterpret_cast<Work *>(message->getObject());
            if (work) {
                double result = calulatePiFor(work->getStart(), work->getNumOfElements());
                this->getSender().tell((void *)new Result(result), getSelf());
            }
        }
        else {
            // UnHandle(message);
        }
    }
};

class WorkerRouter;
class RoundRobinRounter;
class Props {
public:
    Props() {}
    Props(std::string name) {}
};

namespace System {

static
int getAvailableProcessor() {
    return 2;
}

}

class Pi {
public:
    Pi() {}
    ~Pi() {}

    void calculate(int numOfWorkers, int numOfElement, int numOfMessagees) {
        // Create an actor system
        ActorSystem * system = ActorSystem::create("PiSystem");
        if (system) {
#if 0
            // Create the result listener, which will print the result and shutdown the system.
            ActorRef * listener = system->actorOf(new Props(Listener.getClass(), "linstener");
            if (listener) {
                // Create the master
                ActorRef * master = system->actorOf(new Props(new UntypedActorFactory()), "master");
                if (master) {
                    master->tell(new Calculate());
                }
            }
#endif
        }
    }

    static void main(int argn, char * argv[]) {
        Pi * pi = new Pi();
        int numOfProcessor = System::getAvailableProcessor();
        if (pi) {
            pi->calculate(numOfProcessor, 10000, 10000);
        }
    }
};

#endif  /* _AKEE_TEST_PI_H_ */
