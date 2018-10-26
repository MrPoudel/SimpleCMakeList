#include <stdio.h>
#include <pthread.h>
#include <stdbool.h>
#include <signal.h>

bool RUN = 1;


static void stopHandler(int sign) {
    printf("received ctrl-c");
    RUN = false;
}

/* This is our thread function.  It is like main(), but for a thread */
void *threadFunc(void *arg)
{
	signal(SIGINT, stopHandler);
	signal(SIGTERM, stopHandler);

	//RUNNING =false;
	char *str;
	int i = 0;

	str=(char*)arg;

	while(RUN)
	{
		usleep(1);
		printf("threadFunc says: %s\n",str);
		++i;
	}

	usleep(5000);

	return NULL;
}


int main(void)
{
	pthread_t pth;	// this is our thread identifier
	int i = 0;

	/* Create worker thread */
	pthread_create(&pth,NULL,threadFunc,"processing...");

	/* wait for our thread to finish before continuing */
	

	while(RUN)
	{
		usleep(1);
		printf("main() is running...\n");
		++i;
	}

	printf("waiting thread");

	pthread_join(pth, NULL /* void ** return value could go here */);

	return 0;
}