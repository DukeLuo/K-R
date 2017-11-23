/* 练习　5-11 */
/* detab函数　*/

#include <stdio.h>
#include <stdlib.h>

#define MAXLINE 100

void detab(char *to, char *from, int tabwidth)
{
    char *ptr1 = to, *ptr2 = from;
    int i;

    for ( ; *ptr2; ++ptr2) {
        if (*ptr2 == '\t')
            for (i = 0; i < tabwidth; ++i)
                *ptr1++ = ' ';
        else
            *ptr1++ = *ptr2;
    }
    *ptr1 = '\0';
}

int main(int argc, char *argv[])
{
    int len;
    int tabwidth = 4;
    char line[MAXLINE], nline[MAXLINE];
    int mygetline(char *line, int maxline);

    if (argc != 1 && argc != 2) {
        printf("Usage: Replace Tab with a specified number of spaces\n");
        return 0;
    }
    else if (argc == 2)
        tabwidth = atoi(argv[1]);

    while ((len = mygetline(line,MAXLINE)) > 0) {
        detab(nline, line, tabwidth);
        printf("%s", nline);
    }
    return 0;
}


