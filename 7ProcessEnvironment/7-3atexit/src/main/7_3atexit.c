#include "apue.h"

static void my_exit1(void);
static void my_exit2(void);

int main (void )
{
    if (atexit(my_exit2) != 0)
        err_sys("can't register my_exit2");

    if (atexit(my_exit1) != 0)
        err_sys("can't register my_exit1");
    if (atexit(my_exit1) != 0)
        err_sys("can't register my_exit1 second");
    printf("main is done\n");
    return(0);
}

static void my_exit1(void)
{
    static int i = 0;
    
    printf("the %d times exit handler exit1\n", ++i);

}

static void my_exit2(void)
{
    static int i = 0;
    printf("the %d times exit handler exit2\n", ++i);
}
