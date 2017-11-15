/* 练习 5-7 */

#include <string.h>

#define MAXLEN 1000

int mygetline(char *, int);

int readlines(char *lineptr[], int maxlines, char *space, int size)
{
    int len, nlines;
    char line[MAXLEN];
    char *p;

    nlines = 0;
    p = space;
    while ((len = mygetline(line, MAXLEN)) > 0) {
        if (nlines >= maxlines || p+len > space+size)
            return -1;
        else {
        line[len-1] = '\0';
        strcpy(p, line);
        lineptr[nlines++] = p;
        p += len;
        }
    }
    return nlines;
}


