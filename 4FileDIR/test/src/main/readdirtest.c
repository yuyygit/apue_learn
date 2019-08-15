#include "apue.h"
#include <dirent.h>
#include <sys/stat.h>

static char     *fullpath;
static size_t   pathlen;

int main(int argc, char *argv[])
{
    struct stat     statbuf;
    struct dirent   *dirp;
    DIR             *dp;
    int             ret, n;

    if ((dp = opendir(argv[1])) == NULL)
        err_sys("opendir error");

    while((dirp = readdir(dp)) != NULL) {
        if (strcmp(dirp->d_name, ".") == 0||
                strcmp(dirp->d_name, "..") == 0)
            continue;
        printf("%s\n", dirp->d_name);
    }


}
