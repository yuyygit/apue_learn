#include "apue.h"
#include <errno.h>

int main (int argc, char *argv[])
{
    fprintf(stderr, "EACCESS: %s\n", strerror(EACCES));
    errno = ENOENT;
    fprintf(stderr, "EACCESS: %s\n", strerror(EACCES));
    perror(argv[0]);
    exit(0);
}
