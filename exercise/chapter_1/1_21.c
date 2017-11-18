/* 练习 1-21 */

#include <stdio.h>

#define MAXLINE 100
#define TABWIDTH 4

void entab(char *to, char *from)
{
    char *ptr1 = to, *ptr2 = from;
    int i, n;
    int seqblank(char *s);

    for ( ; *ptr2; ++ptr2) {
        if (*ptr2 == ' ') {
            n = seqblank(ptr2);
            ptr2 += n;
            for (i = 0; i < (n+1) / TABWIDTH; ++i)
                *ptr1++ = '\t';
            for (i = 0; i < (n+1) % TABWIDTH; ++i)
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



int main(void)
{
    int len;
    char line[MAXLINE], nline[MAXLINE];
    int mygetline(char *line, int maxline);

    while ((len = mygetline(line,MAXLINE)) > 0) {
        entab(nline,line);
        printf("%s", nline);
    }
    return 0;
}


