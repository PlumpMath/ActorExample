
#include <stdio.h>
#include <stdlib.h>
#include <string>

//#define AKEE_USE_STATICLIB
#include <akee/akee.h>
#include <akee/actor/ActorSystem.h>
#include <akee/actor/ActorBase.h>

using namespace akee;

int main()
{
    only_test_for_api_export();

    ActorBase * actorBase = new ActorBase();
    IActorContext * context = actorBase->getActorContext();
    if (actorBase)
        delete actorBase;

    ActorSystem * actorSystem = ActorSystem::create("Factorial N");
    std::string systemName = actorSystem->getName();
    printf("Welcome to use Akee!\n", 0);
    printf("ActorSystem Name: %s.\n", systemName.c_str());
    printf("\n");
    if (actorSystem)
        delete actorSystem;
    system("pause");
    return 0;
}
