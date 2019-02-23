#include <stdio.h>

int main(void)
{
	int N, number;
	FILE *ifile;

	ifile = fopen("my_first_file.txt", "r"); /* open file for reading
	                                            the "r" stands for reading*/

	fscanf(ifile, "%d", &N);

	printf("There are %d numbers in the file.\n", N);

	for (int i = 0; i < N; ++i)
	{
		fscanf(ifile, "%d", &number);
		printf("I read %d form the file.\n", number);
	}

	fclose(ifile);

	return 0;
}

/*Calculation of Average*/
/*
#include <stdio.h>

int main(void)
{
	int N, number;
	double sum =0, average;
	FILE *ifile;
	
	ifile = fopen("studentGrades.txt", "r"); /* open file for reading
	the "r" stands for reading*/
	
	fscanf(ifile, "%d", &N);
	
	for (int i = 0; i < N; ++i)
	{
		fscanf(ifile, "%d", &number);
		sum += number;
	}
	average = sum/N;
	printf("%0.2lf\n", average);
	
	fclose(ifile);
	
	return 0;
}
*/
