#include "apue.h" 
#include <sys/wait.h>

static void sig_int(int);

int main (void)
{
    char buf[MAXLINE];
    pid_t pid;
    int status;

    if (signal(SIGINT, sig_int) == SIG_ERR)
        err_sys("signal error");
    else
        printf("sig_int register success!\n");

    printf("%% "); /* print prompt (print requires %% to % */
    while (fgets(buf, MAXLINE, stdin) != NULL){
        if (buf[strlen(buf) - 1] == '\n')
            buf[strlen(buf) - 1] = 0; /* replace newline with null */

        if ((pid = fork()) < 0){
            err_sys("fork error");
        } else if (pid == 0) { /* child */
            printf("child\tpid:%ld\n", (long)getpid());
            execlp(buf, buf, (char *)0);
            err_ret("couldn't execute: %s", buf);
            exit(127);

        }

        /* parent */
        if ((pid = waitpid(pid, &status, 0)) < 0)
            err_sys("waitpid error");

        printf("parent\tpid:%ld\n", (long)getpid());
        printf("%% ");
    }
    exit(0);
}

void sig_int(int signo)
{
    printf("interrupt\n");
    printf("%% ");
    fflush(stdout);
}
