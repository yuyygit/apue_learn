#include "apue.h"
#include <stdio.h>
#include <stdlib.h>

void pr_stdio(const char *pathname, FILE *fp);
void my_setbuf(FILE *fp, char *buf);

int main(void)
{
    char buf[MAXLINE];
    char filename[BUFSIZ];
    FILE *fp;

    printf("BUFSIZ = %d\n", BUFSIZ);
    printf("Please input a filename: ");
    scanf("%s", filename);

    if ((fp = fopen(filename, "r")) == NULL)
    {
        printf("fopen error");
        exit(1);
    }
    
    pr_stdio(filename, fp); //查看缓冲类型

    if (fp->_flags & _IO_UNBUFFERED)
        my_setbuf(fp, buf);
    else
        my_setbuf(fp, NULL);

    printf("After setbuf...\n");
    pr_stdio(filename, fp);

    return 0;


}

void pr_stdio(const char *pathname, FILE *fp)
{
    printf("stream = %s, ", pathname);

    if(fp->_flags & _IO_UNBUFFERED)
        printf("unbuffered\n");
    else if (fp->_flags & _IO_LINE_BUF)
        printf("line buffered\n");
    else 
        printf("fully buffered\n");
}

void my_setbuf(FILE *fp, char *buf)
{
    int fd;

    fd = fileno(fp);

    if (buf == NULL)
    {
        setvbuf(fp, buf, _IONBF, BUFSIZ);
        return;
    }

    if (fd == 0 || fd == 1 || fd == 2)
        setvbuf(fp, buf, _IOLBF, BUFSIZ);
    else
        setvbuf(fp, buf, _IOFBF, BUFSIZ);
}
