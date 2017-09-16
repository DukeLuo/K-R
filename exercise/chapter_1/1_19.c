/* 练习 1-19 */

#include <stdio.h>

#define MAXLINE 1000

int getline(char line[], int maxline);
void reverse(char s[]);

int main()
{
    char line[MAXLINE];
    
    while (getline(line, MAXLINE) > 0) {
        reverse(line);
        printf("%s", line);
    }
    return 0;
}


int getline(char s[], int lim)
{
    int c, i;
    
    for(i = 0; i < lim - 2 && (c=getchar()) != EOF && c != '\n'; ++i)
        s[i] = c;
    if (c != EOF) {
        s[i++] = '\n';
        s[i] = '\0';
    }
    return i;
}

void reverse(char s[])
{
    int i, j, c;
    
    for(j = 0; s[j] != '\n'; j++)
        ;
    --j;
    
    for(i = 0; i < j; i++,j--)
        c = s[i], s[i] = s[j], s[j] = c;
}

    