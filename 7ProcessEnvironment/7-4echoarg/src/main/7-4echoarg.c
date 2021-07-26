#include "apue.h"

void Func(char str[100]);

int main(int argc, char *argv[], char strc[100])
{
    int i;
    char str[] = "hello";
    char strd[100];
    char *p;
    int n = 10;
    

    printf("argc = %d\n", argc);

    for (i = 0;argv[i] != NULL; i++)
        printf("argv[%d]: %s\n", i, argv[i]);
    exit(0);
}

void Func(char str[100])
{
    int i = 0;
    printf("func\n");
    return;
}
