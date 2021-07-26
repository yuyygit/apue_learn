#include <stdio.h>

int main(void)
{
    int a =4;
    float b = 3.14f;
    switch (a > b)
    {
        case 0:
            printf("this is 0\n");
            break;
        case 1:
            printf("this is 1\n");
            break;
        case 2:
            printf("this is 2\n");
            break;
        default:
            printf("this is default\n");
    }

    return 0;
}
