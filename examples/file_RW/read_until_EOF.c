#include <stdio.h>

int main(void)
{
	FILE *ifile;
	int num, message, count,sum;
	double average;

	ifile = fopen("my_second_file.txt", "r"); /* open file for reading
	                                           the "r" stands for reading*/
    count = 0;
    sum = 0;

    while(fscanf(ifile, "%d", &num) != EOF)
    {
		printf("I read %d form the file.\n", num);
        sum += num;
        count++;
    }

    average = (double) sum /count;
	printf("There are %d numbers in the file.\n", count);
	printf("Average of %d numbers in the file is %0.2lf.\n", count, average);
		
    fclose(ifile);

	return 0;
}