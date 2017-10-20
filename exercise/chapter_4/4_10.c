/* 练习 4-10 */

#include <stdio.h>
#include <ctype.h>
#include "calc.h"

#define MAXLINE 1000

/* getop函数： 获取下一个运算符或数值操作数 */
int getline(char line[], int maxline);

static int lindex;
static char line[MAXLINE];

int getop(char s[])
{
    int i, c;
    
    if (line[lindex] == '\0') {
        if (getline(line, MAXLINE) == 0)
            return EOF;
        else
            lindex = 0;
    }
    while ((s[0] = c = line[lindex++]) == ' ' || c == '\t')
        ;
    s[1] = '\0';
    if (!isdigit(c) && c != '.')
        return c;
    i = 0;
    if (isdigit(c))
        while (isdigit(s[++i] = c = line[lindex++]))
            ;
    if (c == '.')
        while (isdigit(s[++i] = c = line[lindex++]))
            ;
    s[i] = '\0';
    --lindex;
    return NUMBER;
}

