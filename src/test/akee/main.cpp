
#include <stdio.h>
#include <stdlib.h>

#include <iostream>
#include <string>

#define DEF_ACTORSYSTEM_NOINLINE      // Excluding the static ActorSystem * ActorSystem::createAndStartSystem() method

#include "Pi.h"

int main(int argn, char * argv[])
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

    Pi::main(argn, argv);

    system("pause");
    return 0;
}
