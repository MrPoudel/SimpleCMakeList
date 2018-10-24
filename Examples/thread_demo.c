#include <stdio.h>
#include <pthread.h>


/* This is our thread function.  It is like main(), but for a thread */
void *threadFunc(void *arg)
{
	char *str;
	int i = 0;

	str=(char*)arg;

	while(i < 10 )
	{
		usleep(1);
		printf("threadFunc says: %s\n",str);
		++i;
	}

	return NULL;
}

int main(void)
{
	pthread_t pth;	// this is our thread identifier
	int i = 0;

	/* Create worker thread */
	pthread_create(&pth,NULL,threadFunc,"processing...");

	/* wait for our thread to finish before continuing */
	pthread_join(pth, NULL /* void ** return value could go here */);

	while(i < 10 )
	{
		usleep(1);
		printf("main() is running...\n");
		++i;
	}

	return 0;
}