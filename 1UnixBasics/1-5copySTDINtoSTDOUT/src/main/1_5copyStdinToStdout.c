#include "apue.h"

int main(void)
{
    int c;
    int comm_flag = 0;
    int comm_ptr = 0;
    char comm[6];
    while ((c = getc(stdin)) != EOF)
    {
         
        if (putc(c, stdout) == EOF)
            err_sys("output error"); 
        if (c == ':')
            comm_flag = 1;
        if (comm_flag == 1) {
            comm[comm_ptr++] = c;
        }

        //if (comm_ptr >= 4 && !strncmp(comm, ":exit", 5)) 
        if (comm_ptr >= 5) {
            if(!strncmp(comm, ":exit", 5)) {
                printf("exit now\n");
                exit(0);
                break; 
            } else {
                comm_flag = 0;
                comm_ptr = 0;
            }
        }
    }

    if (ferror(stdin))
        err_sys("input error");

    printf("\n");

    exit(0);

}
