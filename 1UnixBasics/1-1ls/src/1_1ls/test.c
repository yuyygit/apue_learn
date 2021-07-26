#include "apue.h"
#include <dirent.h>
#include "errno.h"



int main (int argc, char *argv[])
{
    DIR *dp;
    struct dirent *dirp;

    printf("argv[0] = %s\n", argv[0]);

    if (argc < 2){
        err_quit("usage: ls directory_nam");
    }

    printf("open argv[1]: %s\n", argv[1]);

    if ((dp = opendir(argv[1])) == NULL)
        err_sys("can't open %s", argv[1]);
    while ((dirp = readdir(dp)) != NULL)
            printf("%s\n", dirp->d_name);

    printf("---------while end-----------");
    closedir(dp);

    for(int i=0; i < argc; i++) {
        printf("i=%d    argv[%d]=%s\n", i, i,argv[i]);
        printf("*(argv+%d)= %s \n", i, *(argv+i));
        printf("*argv= %s \n", *argv);
        printf("point:argv = %p \n", argv);
        printf("point:argv+%d = %p \n", i, argv+i);
        printf("point2:&argv+%d = %p \n", i, &argv[i]);
    }

    exit(0);
}

