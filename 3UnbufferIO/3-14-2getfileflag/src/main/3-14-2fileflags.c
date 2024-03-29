#include "apue.h"
#include <fcntl.h>

int main(int argc, char *argv[])
{
    int val;

    if(argc != 2)
        err_quit("usage: %s <descriptor#>", argv[0]);

    if((val = fcntl(atoi(argv[1]), F_GETFL, 0)) < 0)
        err_sys("fcntl error for fd %d", atoi(argv[1]));

    switch(val & O_ACCMODE){
        case O_RDONLY:
            printf("read only");
            break;
        case O_WRONLY:
            printf("write only");
            break;
        case O_RDWR:
            printf("read write");
            break;
        default:
            err_dump("unkonw access mode");
    }

    if(val & O_APPEND)
        printf(", append");
    if(val & O_NONBLOCK)
        printf(", nonblocking");
    if(val & O_SYNC)
        printf(", synchronous write");

    putchar('\n');
    return 0;
}

