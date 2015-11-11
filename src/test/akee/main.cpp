
#include <stdio.h>
#include <stdlib.h>

#include <akee/akee.h>
#include <akee/actor/ActorSystem.h>

#include <string>

using namespace akee;
using namespace std;

int main()
{
	Actor actor = ActorSystem::create("Factorial N");
	std::string actorName = actor.getName();
	printf("Hello world! Akee!\n", 0);
	printf("Actor Name: %s.\n", actorName.c_str());
	system("pause");
	return 0;
}
