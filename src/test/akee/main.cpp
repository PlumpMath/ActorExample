
#include <stdio.h>
#include <stdlib.h>

#include <akee/akee.h>
#include <akee/actor/ActorSystem.h>

int main()
{
	Actor actor = ActtorSystem.create("hello");
	printf("Hello world! Akee!\n\n", 0);
	return 0;
}
