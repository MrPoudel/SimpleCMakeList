
#include <stdio.h>
void addByOne1(int*); //using one level pointer
void addByOne2(int**); //using two level pointer
int main()
{
    printf("Hello, World!\n");
    int* p;
    int** pp;
    int a = 5;
    
    p = &a;
    pp = &p;
   // int*  pp = p;
    
    addByOne1(p);
    printf("New value using one level pointer is %d\n", *p);
    addByOne2(pp);
    printf("New value using two level pointer is %d\n", **pp);
    
    return 0;
}
void addByOne1(int* x){
    
    ++(*x);
    
}
void addByOne2(int** x){
    
    ++(**x);
    
}
