/* 练习　5-11 */
/* entab函数　*/

#include <stdio.h>
#include <stdlib.h>

#define MAXLINE 100

void entab(char *to, char *from, int tabwidth)
{
    char *ptr1 = to, *ptr2 = from;
    int i, n;
    int seqblank(char *s);

    for ( ; *ptr2; ++ptr2) {
        if (*ptr2 == ' ') {
            n = seqblank(ptr2);
            ptr2 += n;
            for (i = 0; i < (n+1) / tabwidth; ++i)
                *ptr1++ = '\t';
            for (i = 0; i < (n+1) % tabwidth; ++i)
                *ptr1++ = ' ';
        }
        else
            *ptr1++ = *ptr2;
    }
    *ptr1 = '\0';
}

/* seqblank函数：　返回*s后连续的空格个数　*/
int seqblank(char *s)
{
    char *next = s +1;
    int i = 0;

    for ( ; *next == ' '; ++next)
        ++i;
    return i;
}



int main(int argc, char *argv[])
{
    int len;
    int tabwidth = 4;
    char line[MAXLINE], nline[MAXLINE];
    int mygetline(char *line, int maxline);

    if (argc != 1 && argc != 2) {
        printf("Usage: Replace spaces with a specified number of Tab\n");
        return 1;
    }
    else if (argc == 2)
        tabwidth = atoi(argv[1]);


    while ((len = mygetline(line,MAXLINE)) > 0) {
        entab(nline, line, tabwidth);
        printf("%s", nline);
    }
    return 0;
}


