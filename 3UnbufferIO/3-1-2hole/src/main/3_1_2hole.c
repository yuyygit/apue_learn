#include "apue.h"
#include <fcntl.h>

char buf1[] = "abcdefghij";
char buf2[] = "ABCDEFGHIJ";

int main(void)
{
    int fd1, fd2;
    int count = 0;
    if((fd1 = creat("file.hole", FILE_MODE)) < 0)
        err_sys("creat error");

    if(write(fd1, buf1, 10) != 10)
        err_sys("buf1 write error");
    /* offset now = 10 */
    if(lseek(fd1, 16384, SEEK_SET) == -1)
        err_sys("lseek error");
    if(write(fd1, buf2, 10) != 10)
        err_sys("buf2 write error");

    if ((fd2 = creat("file.nohole", FILE_MODE)) < 0)
        err_sys("creat error");
    while(count < 16390)
    {
        if(write(fd2, buf1, 10) != 10)
            err_sys("buf1 write error");
        count += 10;
    
    }
    exit(0);
}


