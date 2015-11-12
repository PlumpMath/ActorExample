
#include <stdio.h>
#include <stdlib.h>

#include <akee/akee.h>

//#define AKEE_USE_STATICLIB

#include <akee/actor/ActorSystem.h>

#include <string>

using namespace akee;

int main()
{
	only_test_for_api_export();

	ActorSystem * actorSystem = ActorSystem::create("Factorial N");
	std::string systemName = actorSystem->getName();
	printf("Hello world! Welcome to use Akee!\n", 0);
	printf("ActorSystem Name: %s.\n", systemName.c_str());
	printf("\n");
	if (actorSystem)
		delete actorSystem;
	system("pause");
	return 0;
}
