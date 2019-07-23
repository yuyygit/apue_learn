#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

void myprintf(const char* fmt, ...)
{
    char* pArg = NULL;
    char c;
    int i = 0;
//    printf("*fmt = %c\n", *fmt);
//    printf("pArg-> %d\n", *pArg);
//    printf("pArg = %p\n", pArg);
//    printf("fmt = %p\n", fmt);
//    pArg = (char *)fmt;
//    //pArg += ((sizeof(fmt)/sizeof(char)) * 2);
//    pArg += (sizeof(char) * 2);
//    printf("fmt--->%p\n",fmt);
//    printf("pArg--->%p\n",pArg);
//    printf("fmt = %c\n", *fmt);
//    printf("pArg = %c\n", *pArg);
//    printf("int pArg = %d\n", *((int *)pArg));
//    printf("pArg + 1= %p\n", (pArg +1));
//    printf("pArg + char = %p \n", (pArg + sizeof(char)));
//    printf("pArg int * = %p \n", (int *)pArg);
//    printf("pArg char printf: %c\n", *(int *)pArg);
//    printf("pArg char printf: %c\n", *(int *)pArg);


    do
    {
        c = *fmt;
        if(c != '%')
        {
            putchar(c);
            ++fmt;
            
        }
        else
        {
            if(i == 0)
            {
                printf("fmt = %c\n", *fmt);                
                pArg = (char*)fmt;
                printf("pArg = %c\n", *pArg);
                
                //pArg += ((sizeof(fmt)/sizeof(char)) * 2);
                //pArg += ((sizeof(char)) * 2);
                pArg += (sizeof(char) * 4);
                printf("pArg = %c\n", *pArg);
                i=1;
                printf("fmt--->%p\n",fmt);
                printf("pArg--->%p\n",pArg);
            
            }
            switch(*++fmt)
            {
                case 'd':
                    //printf("%d", *((int*)pArg));
                    printf("%c", (*(int *)pArg));
                    break; 
                case 'x':
                    printf("%#x", (*(int *)pArg));     
                    break;
                default:
                    break;
            
            }
            pArg += sizeof(int);
        }
    
    }while(*fmt != '\0');
  
    printf("\n");
    pArg = NULL;
    return;
}
int main(void)
{
    int i = 1234;
    int j = 5678;
    myprintf("the first test i=%d", i);    
//    myprintf("the first test i=%d", i);    
//    myprintf("the second test: i=%d; %x; j=%d",i, 0xabcd,j);
    return 0;
}
