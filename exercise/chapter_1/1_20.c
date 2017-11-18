/* 练习　1-20 */

#include <stdio.h>

#define MAXLINE 100
#define TABWIDTH 4

void detab(char *to, char *from)
{
    char *ptr1 = to, *ptr2 = from;
    int i;

    for ( ; *ptr2; ++ptr2) {
        if (*ptr2 == '\t')
            for (i = 0; i < TABWIDTH; ++i)
                *ptr1++ = ' ';
        else
            *ptr1++ = *ptr2;
    }
    *ptr1 = '\0';
}

int main(void)
{
    int len;
    char line[MAXLINE], nline[MAXLINE];
    int mygetline(char *line, int maxline);

    while ((len = mygetline(line,MAXLINE)) > 0) {
        detab(nline,line);
        printf("%s", line);
        printf("%s", nline);
    }
    return 0;
}
    

