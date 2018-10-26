
//Function pointer as a argument to another
#include <stdio.h>

void callback(int times, const char* name){

	for (int i = 0; i < times; ++i)
	{
		printf("%s\n", name);
	}
}

void call_callback(void (*ptr) (int , const char* )){
	ptr(5, "Calling via another function");
}

int main(){

	void (*p) (int, const char*);
	p = &callback;
	p(2, "Direct calling!");
	call_callback(p); //call(p1(5, "Shulpha")); 
	p(2, "Direct calling again!");
	
	return 0;
}