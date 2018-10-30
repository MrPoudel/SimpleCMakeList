#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <stdbool.h>
#include <unistd.h>
#include <pthread.h>

// Stop handler
bool running = true;
static void stopHandler(int sign) {
    printf("received ctrl-c");
    running = false;
}


/* Structure for passing data to threads */
typedef struct _shared
{
	int i; /* row */
	char* j; /* column */
} shared;

  
/*thread function definition*/
void* threadFunction(void* args)
{
	shared *data_arg = (shared *) args;
   // data_arg -> i = 10;

    while(running)
    {
        printf("I am threadFunction.\n");
        printf("Thread:shared data[i]=%d\n", data_arg->i) ; 
    }

    printf("Thread has been exited!");

    sleep(1);

    pthread_exit(0);
}


int main()
{
	signal(SIGINT, stopHandler);
    signal(SIGTERM, stopHandler);
    /*creating thread id*/
    pthread_t id;
    int ret;
	
	shared *data = (shared *) malloc(sizeof(shared));
	data -> i = 10;
	data -> j = "test";

  
    /*creating thread*/
    if(ret = pthread_create(&id,NULL,&threadFunction, data))
    {
      fprintf(stderr, "error: pthread_create, rc: %d\n", ret);
      return EXIT_FAILURE;
    }
    else {

        printf("Thread created successfully.\n");

    }
    
    while(running)
    {
      printf("I am main function.\n");  
      printf("Main:shared data[i]=%d\n", data->i) ;   
    }

   //What happens when user presses hte control-c
    //Main thread as well as worker threads try to exit as soon as possible
    //which one is first is decided by the OS
    //if thread exits first it's okay
    //if main exits first then the thread will join to the main after delay of one second -->sleep(1)
    //Finally, everything is fine!
    
    pthread_join(id, NULL);

    return 0;
}