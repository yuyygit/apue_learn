#include "apue.h"
#include "errno.h"

int main(int argc, char *argv[])
{

    printf("stderr: EINTR: %s\n", strerror(EINTR));
    printf("----------error num------------\n");

    for (int error_num = 0; error_num <= 256; error_num++) {
        printf("error: %2d\t%s\n", error_num, strerror(error_num));
    }
    exit(0);

}
