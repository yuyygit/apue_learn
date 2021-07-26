#include <stdio.h>

int test(int *);
int main(void)
{
    int a = 5, b =6, c = 7, d = 8, m = 2, n = 2;
    (m = a > b)&&(n = c < d);
    printf("%d\t%d\n", m , n);

    test(&a);
    printf("a = %d\n", a);
    return 0;
}

int test(int *x)
{
    *x = *x + 10;
    return *x;
}
