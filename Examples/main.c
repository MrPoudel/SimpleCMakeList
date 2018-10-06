#include <stdio.h>
#include "cube.h"
#include "square.h"

int main()
{
  int i;
  printf("Enter the number:\n");
  scanf("%d",&i);
  f_square(i);
  f_cube(i);
  return 0;
}
