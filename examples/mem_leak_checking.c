#include<stdio.h>
#include<stdlib.h>

void doSomething(void){
	int* x = malloc(10 * sizeof(int));
	x[10] = 0;	
}

int main(void){
	doSomething();
	return 0;
}