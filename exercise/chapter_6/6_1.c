/* 练习　6-1 */

#include <stdio.h>
#include <ctype.h>

/* getword函数：　从输入中读取下一个单词或字符　*/
int getword(char *word, int lim)
{
    int c;
    char *w = word;
    int getch(void);
    void ungetch(int);

    while (isspace(c=getch()))
        ;
    if (c != EOF)
        *w++ = c;
    if (!isalpha(c) && c != '_' && c != '#') {
        if (c == '"') {
            while (--lim)
                if ((*w++ = getch()) == '"') {
                    *w = '\0';
                    return word[0];
                }
        } else if (c == '/') {
            if ((c = getch()) == '/')       //行注释
                while ((c = getch()) != '\n')
                    ;
            else                            //段注释
                while ((c = getch()) != '/')
                    ;
            *w = '\0';
            return '/';
        } else {
            *w = '\0';
            return c;
        }
    }
    while (--lim > 0)
        if (isalnum(c = getch()) || c == '_' || c == '#')
            *w++ = c;
        else {
            ungetch(c);
            break;
        }
    *w = '\0';
    return word[0];
}


int main(void)
{
    char x[50];

    while (getword(x, 50) != EOF)
        printf("%s\n", x);
    return 0;
}


