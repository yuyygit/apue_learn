#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>

#define SELF_INTSIZEOF(n) ((sizeof(n) + sizeof(int)-1) &~ (sizeof(int) -1))

void testVa(char *fmt, ...)
{
	va_list ap;
	va_start(ap, fmt);
//	vsnprintf();

}

int main(void)
{
    int testnum;
    int a;
	int numlist[3] = {10, 21, 32};
    int *b; 
    int *c;
    int testvale = 5;
    int *d;

    b = &numlist[0];
    d = &numlist[0];

    printf("b raw_located at : %p\n", b);

    c = &(*(int *)((b += (int)SELF_INTSIZEOF(int)) - SELF_INTSIZEOF(int)));
    
    
   printf("d value = %d \n", *d); 
   printf("d second value = %d \n" , *++d);
    
    
    printf("b located at : %p\n", b);
    printf("c located at : %p\n", c);
    printf("b point value: %d\n", *b);
    b +=  1;
    printf("b last two value: %p\n", b);

    b +=  (int)SELF_INTSIZEOF(int);
    printf("b last one value: %p\n", b);
    
    printf("c point value: %d\n", *c);
    printf("numlist[0] = %p\n", &numlist[0]);
    printf("numlist[1] = %p\n", &numlist[1]);
    printf("numlist[2] = %p\n", &numlist[2]);
    printf("int SIZEOF = %d\n", (int)SELF_INTSIZEOF(int));

    /*
    printf("sizeof(numlist) = %d\n", (int)sizeof(numlist) );
    a =  (int)(sizeof(numlist)/sizeof(int)); 
    testnum = SELF_INTSIZEOF(numlist);
    printf("sizeof numlist = %d\n",a);
    //    printf("");
    printf("testnum = %d\n", testnum);
    */
    return 0;

}
