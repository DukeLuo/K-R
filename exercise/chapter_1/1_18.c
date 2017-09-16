/* 练习 1-18 */

#include <stdio.h>

#define MAXLINE 1000

int getline(char line[], int maxline);
int remove_tab_space(char s[]);

int main()
{
    char line[MAXLINE];
    
    while(getline(line, MAXLINE) > 0)
        if (remove_tab_space(line) > 0)
            printf("%s", line);
    return 0;
}


int getline(char s[], int lim)  // 修改getline使得到的每行都以'\n'结尾，
{                               // 简化情况，易于处理
    int c, i;
    
    for(i = 0; i < lim - 2 && (c=getchar()) != EOF && c != '\n'; ++i)
        s[i] = c;
    if (c != EOF) {
        s[i++] = '\n';
        s[i] = '\0';
    }
    return i;
}

int remove_tab_space(char s[])
{
    int i;
    
    i = 0;
    while(s[i] != '\n')
        ++i;
    --i;
    while(i >= 0 && (s[i] == ' ' || s[i] == '\t'))
        --i;
    if(i >= 0) {
        s[++i] = '\n';
        s[++i] = '\0';
    }
    return i;
}

    