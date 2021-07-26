#include "apue.h"

#define COMMAND_LENTH 6

int main(int argc, char *argv[])
{
    char c;
    int command_flag;
    char *command_chr[COMMAND_LENTH]; 

    while ( (c = getc(stdin)) != EOF) {
        if (putc(c,stdout) == EOF)
            err_sys("output error");
    }

    if (ferror(stdin))
        err_sys("input error\n");

    printf("stdin -> stdout stop&exi\n");
    exit(0);
}
