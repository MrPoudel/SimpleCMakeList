#include <stdio.h>
#include "cube.h"
#include "square.h"

int main()
{
  int i;
  printf("Enter the number:\n");
  scanf("%d",&i);
  //Function to calculate square of a number
  f_square(i);
  //Function to calculate cube of a number
  f_cube(i);
  return 0;
}
