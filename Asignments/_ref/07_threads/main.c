#include <unistd.h>
#include <pthread.h>
#include<stdio.h>
#include <stdlib.h>


static void * greetWorld(void *arg)
{

	int i = 10;
	while(i--)
	{
		printf("Hello world\n");
		sleep(5);
	}
}

static void * greetIndia(void *arg)
{
	int i = 10;
	while(i--)
	{
		printf("Hello India\n");
		sleep(1);
	}
}

int main()
{

	pthread_t tid = 0;

	pthread_create(&tid, NULL, greetWorld, NULL);

	greetIndia(NULL);

	pthread_join(tid, NULL);
	exit(EXIT_SUCCESS);
}
