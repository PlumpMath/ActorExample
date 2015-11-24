

#include <stdio.h>
#include <stdlib.h>

#include <iostream>
#include <string>

#include "Pi.h"

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

    system("pause");
    return 0;
}
