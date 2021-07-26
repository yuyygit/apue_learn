#include "apue.h"

int main(int argc, char *argv[])
{
    printf("hello test process: %ld\n", (long)getpid());
    exit(0);
}
