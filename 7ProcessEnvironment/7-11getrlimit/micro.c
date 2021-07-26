#include <stdio.h>

int test(int , int *);

int main(void)
{
    int ret  = 0; 
    test(100, &ret);
    printf("%d\n", ret);
    return 0;
}

int test(int n, int *sum)
{
    n && test(n - 1 , sum);
    return *sum += n ; 
}
