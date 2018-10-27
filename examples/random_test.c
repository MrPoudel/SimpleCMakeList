//Random test
#include <stdio.h>


int main(){
	

	int A = 65;
	
	int zeroi = 0;

	char zeroc = 0;

	
	printf("Should not print 0  %c\n", zeroc); //Because 0 in the form of character is '\0'
	printf("Should print 0 %c\n", zeroi); //We are just printing int with value 0

	char nulltermic ='\0';
	int nulli = 36;
	char nullc = 36;

	printf("Null character is  %c\n",nulltermic); //prints 36

    printf("Null character is %d\n",nulltermic); //prints 36

    
    printf("Again nulli as character %c\n",nulli); //prints 0
    printf("Again nullc as int %c\n",nullc); //prints 0

    printf("Again nullc as character %c\n",nullc); //prints 0


	char x = 65;
	
	char test1 = '#';

	int test2 = 0;
	printf("%c\n",test2);

    test2 += 1;
    printf("%d\n",test1);
    printf("%c\n",test1);

	printf("%d\n",x);

	printf("%c\n",test2); //blah blah :D 
	printf("%d\n",test2);
	
	return 0;
}