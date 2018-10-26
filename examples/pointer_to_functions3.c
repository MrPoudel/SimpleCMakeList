
//Function pointer as a return type
#include <stdio.h>

int callback(int times, const char* name){

	for (int i = 0; i < times; ++i)
	{
		printf("%s\n", name);
	}

	return times;
}

void call_callback(int (*ptr) (int , const char* )){
	
	printf("callback was \
called :%d times\n", ptr(5, "Calling via another function"));
}

int main(){

	int (*p) (int, const char*);
	p = callback;
	//p(2, "Direct calling!");
	call_callback(p); //call(p1(5, "Shulpha")); 
	//p(2, "Direct calling again!");
	
	return 0;
}