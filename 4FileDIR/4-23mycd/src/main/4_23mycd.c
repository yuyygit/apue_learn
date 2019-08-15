#include "apue.h"

int main(void)
{
    char buf[128];
    printf("%s\n", getcwd(buf, sizeof(buf)));
    if (chdir("./bin") < 0)
        err_sys("chdir failed");
    printf("child to ./bin succeded\n");
    printf("%s\n", getcwd(buf, sizeof(buf)));
    return 0;
}
