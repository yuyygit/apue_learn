#include "apue.h"

#include <sys/wait.h>

int main(void)
{
    char buf[MAXLINE]; /* from apue.h */
    pid_t pid;
    int status;
    
    printf("raw parent pid: %ld\n", (long)getpid());
    printf("%% "); /* print prompt () printf requires %% to print % */
    while (fgets(buf, MAXLINE, stdin) != NULL){
        if(buf[strlen(buf) - 1] == '\n')
            buf[strlen(buf) - 1] = 0; /* replace newlin with null */
        if ((pid = fork()) < 0){
            err_sys("fork error");
        }

        /* parent */
        else if (pid == 0){ /* child */
            execlp(buf, buf, (char *)0);
            printf("child running.. \n");
            err_ret("couldn't execute: %s", buf);
            printf("child exit: %ld\n", (long)getpid());
            exit(127);
        }
        if ((pid = waitpid(pid, &status, 0)) < 0)
            err_sys("waitpid error");
        if (pid == 0)
            printf("This is child\n");
        printf("%% ");
    }

    if (pid) {
        printf("last child pid：%d\n", pid);
        printf("parent pid：%ld\n", (long)getpid());
    }
    else {
        printf("child pid: %ld\n", (long)getpid());
    }
    exit(0);
}
