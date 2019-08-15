/* 测试chown */
#include "apue.h"
#include <sys/stat.h>

int main(void)
{
    struct stat statbuf;
    
    if (stat("foo", &statbuf) < 0)
        err_sys("stat error for foo");
    if (chown("foo", 1001, 1001 ) < 0)
        err_sys("chown error for foo");

    return 0;
}
