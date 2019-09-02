#include <stdio.h>
#include <stdlib.h>


//Add two number
int AddTwoNumber(int iData1, int iData2)
{
   return(iData1 + iData2);
}


//Subtract two number
int SubTwoNumber(int iData1, int iData2)
{
   return(iData1 - iData2);
}


//Multilply two number
int MulTwoNumber(int iData1, int iData2)
{
   return(iData1 * iData2);
}


// Main function
int main(int argc, char *argv[])
{
   int iRetValue = 0;

//Declaration of array of function pointer
   int (*apfArithmatics[3])(int, int) = { AddTwoNumber, SubTwoNumber, MulTwoNumber };
//Calling the Add function using index of array
   iRetValue = (*apfArithmatics[0])(20, 10);
//display addition of two number
   printf("\n\nAddition of two number = %d\n\n", iRetValue);
//Calling the subtract function using index of array
   iRetValue = (*apfArithmatics[1])(20, 10);
//display subtraction of two number
   printf("\n\nsubtraction of two number = %d\n\n", iRetValue);
//Calling the multiply function using index of array
   iRetValue = (*apfArithmatics[2])(20, 10);
//display multiplication  of two number
   printf("\n\nmultiplication of two number = %d\n\n", iRetValue);
   return(0);
}