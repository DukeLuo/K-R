/* 练习 1-16 */

#include <stdio.h>
#define MAXLINE 1000

int getline(char line[], int maxline);
void copy(char to[], char from[]);

int main()
{
    int len;
    int max;
    char line[MAXLINE];
    char longest[MAXLINE];
    
    max = 0;
    while((len = getline(line, MAXLINE)) > 0) {
        printf("%d: %s\n", len, line);
        if (len > max) {
            max = len;
            copy(longest, line);
        }
    }
    if (max > 0)
        printf("Longest is %d characters:\n%s", max, longest);
    return 0;
}

int getline(char s[], int lim)
{
    int c, i, j; // i统计长度， j数组下标
    
    for(i = 0, j = 0; (c=getchar()) != EOF && c != '\n'; ++i) 
        if (j < lim - 1) {
            s[j++] = c;
        }
    if (c == '\n') {
        if (j < lim - 1) {
            s[j++] = c;
        }
        ++i;
    }
    s[j] = '\0';
    return i;
}

void copy(char to[], char from[])
{
    int i;
    
    i = 0;
    while ((to[i] = from[i]) != '\0')
        ++i;
}

