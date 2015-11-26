

#include <stdio.h>
#include <stdlib.h>

#include <iostream>
#include <string>

#include <memory>
#include <vector>
#include <functional>

#include "Pi.h"

#include "akee/utils/RoundTo.h"
#include "akee/queue/RingQueue.h"

class A {};

template <class T>
class SimpleObjectPool
{
public:
    using DeleterType = std::function<void(T*)>;

    void add(std::unique_ptr<T> t)
    {
        pool_.push_back(std::move(t));
    }

    std::unique_ptr<T, DeleterType> get()
    {
        if (pool_.empty())
        {
            throw std::logic_error("no more object");
        }

        // every time add custom deleter for default unique_ptr
        std::unique_ptr<T, DeleterType> ptr(pool_.back().release(), [this](T* t)
        {
            pool_.push_back(std::unique_ptr<T>(t));
        });

        pool_.pop_back();
        return std::move(ptr);
    }

    bool empty() const
    {
        return pool_.empty();
    }

    size_t size() const
    {
        return pool_.size();
    }

private:
    std::vector<std::unique_ptr<T>> pool_;
};

// ≤‚ ‘¥˙¬Î
void test_object_pool()
{
    SimpleObjectPool<A> p;
    p.add(std::unique_ptr<A>(new A()));
    p.add(std::unique_ptr<A>(new A()));
    {
        auto t = p.get();
        std::cout << "p.get() = " << t.get() << std::endl;
        t = p.get();
        std::cout << "p.get() = " << t.get() << std::endl;
        std::cout << std::endl;
    }

    {
        std::cout << "p.get() = " << p.get().get() << std::endl;
        std::cout << "p.get() = " << p.get().get() << std::endl;
        std::cout << std::endl;
    }

    {
        auto t = p.get();
        std::cout << "p.get() = " << t.get() << std::endl;
        t = p.get();
        std::cout << "p.get() = " << t.get() << std::endl;
        t = p.get();
        std::cout << "p.get() = " << t.get() << std::endl;
        std::cout << std::endl;
    }

    {
        auto t1 = p.get();
        std::cout << "p.get() = " << t1.get() << std::endl;
        auto t2 = p.get();
        std::cout << "p.get() = " << t2.get() << std::endl;
        //auto t3 = p.get();
        //std::cout << "p.get() = " << t3.get() << std::endl;
        std::cout << std::endl;
    }

    std::cout << std::endl;
    std::cout << p.size() << std::endl;
    std::cout << std::endl;
}

int main(int argn, char * argv[])
{
    only_test_for_api_export();

    ActorBase * actorBase = new ActorBase();
    if (actorBase) {
        IActorContext * context = actorBase->getActorContext();
        if (context) {
            context->release();
            delete context;
        }
        delete actorBase;
    }

    ActorSystem * actorSystem = ActorSystem::create("Factorial N");
    if (actorSystem) {
        std::string systemName = actorSystem->getName();
        printf("Welcome to use Akee!\n", 0);
        printf("ActorSystem Name: %s.\n", systemName.c_str());
        printf("\n");
        delete actorSystem;
    }

    Pi::main(argn, argv);

    int a, b, c;
    a = b = c = 1;
    const char * text = StringUtils::format(128, "a = %d, b = %d, c = %d.\n", a, b, c);
    std::cout << text << std::endl;

    text = StringUtils::format(128, "c = %d, b = %d, a = %d.\n", c, b, a);
    std::cout << text << std::endl;

    test_object_pool();

    RingQueueBase<uint64_t, 32> queue;
    queue.capacity();

    int isPow2 = akee::utils::is_pow_of_2<121>::value;
    std::cout << "isPow2(121) = " << isPow2 << std::endl;

    isPow2 = akee::utils::is_pow_of_2<128>::value;
    std::cout << "isPow2(128) = " << isPow2 << std::endl;

    size_t pow2 = akee::utils::round_up_to_pow2<33>::value;
    std::cout << "pow2(33) = " << pow2 << std::endl;

    std::cout << std::endl;
    system("pause");
    return 0;
}
