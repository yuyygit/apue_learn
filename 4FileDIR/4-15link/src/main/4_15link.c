/* 测试link */
#include "apue.h"
#include <fcntl.h>

int main(void)
{
    int fd;
    char buf[] = "hello world\n";
    if ((fd = open("tempfile", O_RDWR | O_CREAT)) < 0)
        err_sys("open error");
    if (write(fd, buf, strlen(buf) + 1) != strlen(buf) + 1)
        err_sys("write error");
    if (link("tempfile", "tempfile2") < 0)
        err_sys("link error");
    if (unlink("tempfile") < 0)
        err_sys("unlink error");

    return 0;
}
