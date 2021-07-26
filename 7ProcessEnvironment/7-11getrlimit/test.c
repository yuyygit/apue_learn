#include <stdio.h>
#include "a.h"
#include "b.h"
#include "string.h"

typedef enum{False,True} boolean;

int main(void)
{
    float x = 0.0f;
    int z;
    boolean y = False;
    const float ESP = 0.000001f;

    if (x >= -ESP && x <= ESP) 
        printf("yes\n");
    else
        printf("no");

    strcpy(st1.name, "hello");
    printf("st1.name : %s\n", st1.name);
    printf("d = %d\n", d);
    return 0;
}
