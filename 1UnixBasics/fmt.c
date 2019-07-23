#include <stdarg.h>
#include <stdio.h>

int sum(int, ...);

int main(void)
{
    printf("10,20,30的和 = %d\n", sum(3,10,20,30));
    printf("5,25,20,30的和 = %d\n", sum(4,5,25,20,30));

    return 0;

}

int sum(int num_args, ...)
{
    int val = 0;
    va_list ap;
    int i;
    va_start(ap, num_args);
    for(i = 0; i < num_args; i++)
    {
        val += va_arg(ap, int);


    }
    va_end(ap);

    return val;
}
