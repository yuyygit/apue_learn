/* 测试uname/gethostname */
#include "apue.h"
#include <sys/utsname.h>
#include <unistd.h>

int main(void)
{
    int ret;
    char buf[64];
    struct utsname myuname;
    if ((ret = uname(&myuname)) < 0)
        err_sys("uname error");
    else
        printf("%s\t%s\t%s\t%s\t%s\n", myuname.sysname, myuname.nodename,
                myuname.version, myuname.release, myuname.machine);
    
    if (gethostname(buf, sizeof(buf)) < 0)
        err_sys("gethostname error");
    printf("hostname:%s\n", buf);

    return 0;
}
