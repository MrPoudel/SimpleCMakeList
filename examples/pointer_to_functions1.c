
//This is simple function pointer demo
#include <stdio.h>

static int mul(int a, int b){
	return a*b;
}

int main(){

	int result;
	int (*p1) (int,int);
	int (*p2) (int,int);
	p1 = &mul;
	result = (*p1) (9,7);
	printf("%d\n", result);

	//Alternatively
	p2 = mul;
	result = p2(10,3);
	printf("%d\n",result);

	//Again
	int (*p3) (int,int) = mul;
	result = p3(20,5);
	printf("%d\n",result);

	return 0;
}