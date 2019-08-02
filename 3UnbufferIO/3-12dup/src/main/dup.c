#include "apue.h"

int main(void)
{
    int fd = dup(STDIN_FILENO);
    if(-1 == fd)
        err_sys("dup stdin failed");
    printf("fd:%d\n", fd);

    int result = dup2(100 , fd);
    if(-1 == result)
        err_sys("dup2 100 failed");
    printf("fd:%d\n", fd);
    return 0;
}
