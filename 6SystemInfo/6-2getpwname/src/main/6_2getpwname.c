/* 测试getpwnam */
#include "apue.h"
#include <pwd.h>
#include <stddef.h>
#include <string.h>

struct passwd *getpwnam(const char *name)
{
    struct passwd *ptr;

    setpwent();
    while((ptr = getpwent()) != NULL)
        if (strcmp(name, ptr->pw_name) == 0)
            break;      /* found a match */ 
    endpwent();
    return ptr; /* ptr is NULl if no match found */
} 

int main(int argc, char *argv[])
{
    struct passwd *ptr;
    if (argc != 2)
        err_quit("usage: %s name", argv[0]);
    ptr = getpwnam(argv[1]);
    if (ptr)
    {
        printf("Get %s : %u\n", argv[1], ptr->pw_uid);
    }
    else
    {
        printf("Invaild parameter");
    }

    return 0;
}
