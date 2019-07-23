#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

void var_args_func(const char * fmt, ...)
{
    char *ap;
    ap = ((char *)&fmt) + sizeof(fmt);
    printf("%d\n", *(int *)ap);

    ap = ap + sizeof(int);
    printf("%d\n", *(int *)ap);

    ap = ap + sizeof(int);
    printf("%s\n",*(char **)ap);

}
void viewArgsAddr(const char* a, char b, char c, char d, char e, char f)
{
    printf("a addr = %p\n", &a);
    printf("b addr = %p\n", &b);
    printf("c addr = %p\n", &c);
    printf("d addr = %p\n", &d);
    printf("e addr = %p\n", &e);
    printf("f addr = %p\n", &f);
}
void viewArgsAddr_contr(char a, int b, char c,unsigned int d, char e, char f)
{
    printf("sizeof char : %d\n", (int)sizeof(char));
    printf("&a + sizeof(char) = %p\n", (&a + sizeof(char)));
    printf("a addr = %p\n", &a);
    printf("b addr = %p\n", &b);
    printf("c addr = %p\n", &c);
    printf("d addr = %p\n", &d);
    printf("e addr = %p\n", &e);
    printf("f addr = %p\n", &f);
}

int main(void)
{
    int i = 0;
    int j = 0;
    var_args_func("%d %d %s\n", 4, 5, "hello");
    viewArgsAddr("hello", 4, 5, 6, 7, 8);
    viewArgsAddr_contr( 3, 4, 5, 6, 7, 8);
    
    
    for (i = 0; i < 3; i++)
    {
        j++;    
    }

//    var_args_func("%d %d %s\n",4,5,"hello world");
//    var_args_func("%d%d%s\n",4,5,"vart");
//    myprintf("the first test i=%d", i);    
//    myprintf("the first test i=%d", i);    
//    myprintf("the second test: i=%d; %x; j=%d",i, 0xabcd,j);
    return 0;
}
