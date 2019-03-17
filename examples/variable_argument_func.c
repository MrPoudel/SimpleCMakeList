
//The function foo takes a string of format characters and prints out the
//argument associated with each format character based on the type.
//We can input any arbitary number of arguments
#include <stdio.h>
#include <stdarg.h>

void
foo(char *fmt, ...)
{
   va_list ap;
   int d;
   char c, *s;

   va_start(ap, fmt);
   while (*fmt)
       switch (*fmt++) {
       case 's':              /* string */
           s = va_arg(ap, char *);
           printf("string %s\n", s);
           break;
       case 'd':              /* int */
           d = va_arg(ap, int);
           printf("int %d\n", d);
           break;
       case 'c':              /* char */
           /* need a cast here since va_arg only
              takes fully promoted types */
           c = (char) va_arg(ap, int);
           printf("char %c\n", c);
           break;
       }
   va_end(ap);
}

int main()
{
	foo("%c%d%c%c%c",'x', 9,'A','B','C');
	//foo("%c%d%c%c%c",'x', 9,'A'); //if this line is uncommented it will print garbage values
	printf("\n");
	foo("d", 5); //% does not matter. Inside the switch statement it will only look for s,d or c.
	foo("s", "Hello");
	return 0;
}
