/* 2.7 类型转换 */

#include <stdio.h>
#define MAXLINE 1000

int atoi(char s[]);
int getline(char line[], int maxline);

int main()
{
    char line[MAXLINE];
    
    while(getline(line,MAXLINE) > 0)
        printf("%d", atoi(line));
    return 0;
}
    
int atoi(char s[])
{
    int i, n;
    
    n = 0;
    for(i = 0; s[i] >= '0' && s[i] <= '9'; ++i)
        n = 10 * n + (s[i] - '0');
    return n;
}

int getline(char s[], int lim)
{
    int c, i;
    
    i = 0;
    while(i < lim - 1) {
        c = getchar();
        if (c == '\n')
            break;
        else if (c == EOF)
            break;
        else
            s[i++] = c;
    }
    if (c == '\n') {
        s[i++] = c;
    }
    s[i] = '\0';
    return i;
}

