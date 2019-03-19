#include <stdio.h>
 
 /* type declartion of function pointer */
typedef  int (*pfunctPtr)(int, int);
 
/*function add two number*/
int AddTwoNumber(int iData1 ,int iData2)
{
  return (iData1 + iData2);
}
 
/*function subtract two number*/
int SubTwoNumber(int iData1 ,int iData2)
{
  return (iData1 - iData2);
}
 
/*function multiply two number*/
int MulTwoNumber(int iData1 ,int iData2)
{
  return (iData1 * iData2);
}
 
//Return function pointer
pfunctPtr ArithMaticOperation(int iChoice) 
{
 //function pointer
 pfunctPtr pArithmaticFunction = NULL;
 
 switch(iChoice)
 {
 case 1:
 
 pArithmaticFunction = AddTwoNumber;
 
 break;
 
 case 2:
 
 pArithmaticFunction = SubTwoNumber;
 
 break;
 
 case 3:
 
 pArithmaticFunction = MulTwoNumber;
 
 break;
 
 }
 
 
 return pArithmaticFunction;
}
 
 
 
int main(void)
{
  int iData1 = 0;
  int iData2 = 0;
  int iChoice = 0;
  int Result = 0;
  pfunctPtr pArithmaticFunction = NULL; //function pointer
 
  printf("Enter two Integer Data \n\n");
  scanf("%d%d",&iData1,&iData2);
  
  printf("Enter 1 for Addition \n\n");
  printf("Enter 2 for Subtraction \n\n");
  printf("Enter 3 for Multiplication \n\n");
  
  scanf("%d",&iChoice);
  
  pArithmaticFunction = ArithMaticOperation(iChoice);
  
  //verify the pointers
  if(pArithmaticFunction != NULL)
  {
   Result = (*pArithmaticFunction) (iData1,iData2);
    printf("Result  = %d\n\n",Result);
  }
  else
  {
   printf("Please enter the valid choice\n");
  }
  
  return 0;
}