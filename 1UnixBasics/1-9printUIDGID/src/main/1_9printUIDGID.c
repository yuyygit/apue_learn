#include "apue.h"

int main(void)
{
    printf("uid = %d,\t gid = %d,\t  pid= %d\n", getuid(), getgid(), getpid());
    exit(0);
}
