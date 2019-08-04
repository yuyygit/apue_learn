#include "apue.h"
#include <errno.h>

void make_temp(char *);

int main(void)
{
    char good_template[] = "./tmp/dirXXXXXX"; // right way
    char *bad_template = "/tmp/dirXXXXXX"; //wrong way
    printf("trying to create first temp file...\n");
    make_temp(good_template);
    printf("trying to create second temp file...\n");
    make_temp(bad_template);
    return 0;


}

void make_temp(char *temp)
{
    int fd;
    struct stat sbuf;

    if((fd = mkstemp(temp)) < 0)
        err_sys("can't create temp file");
    printf("temp name = %s\n", temp);
//    getchar();
    close(fd);

    if (stat(temp, &sbuf) < 0) {
        if (errno == ENOENT)
            printf("file doesn't exist\n");
        else
            err_sys("stat failed");
    } else {
        printf("file exists\n");
        unlink(temp);
    }
}
