/* 5.10 命令行参数　*/
/* find函数：　打印所有与第一个参数指定的模式相匹配的行　*/

/*
#include <stdio.h>
#include <string.h>
#define MAXLINE 1000

int mygetline(char *line, int maxline);

int main(int argc, char *argv[])
{
    char line[MAXLINE];
    int found;

    found = 0;
    if (argc != 2)
        printf("Usage: find pattern\n");
    else
        while (mygetline(line, MAXLINE) > 0)
            if (strstr(line, argv[1]) != NULL) {
                printf("%s", line);
                ++found;
            }
    return found;
}
*/



#include <stdio.h>
#include <string.h>
#define MAXLINE 1000

int mygetline(char *line, int maxline);

int main(int argc, char *argv[])
{
    char line[MAXLINE];
    long lineno = 0;
    int c, except = 0, number = 0, found = 0;

    while (--argc > 0 && (*++argv)[0] == '-') {
        while ((c = *++argv[0])) 
            switch (c) {
            case 'x':
                except = 1;
                break;
            case 'n':
                number = 1;
                break;
            default:
                printf("find: illegal option %c\n", c);
                argc = 0;
                found = -1;
                break;
            }
    }
    if (argc != 1)
        printf("Usage: find -x -n pattern\n");
    else
        while (mygetline(line, MAXLINE) > 0) {
            lineno++;
            if ((strstr(line, *argv) != NULL) != except) {
                if (number)
                    printf("%ld:", lineno);
                printf("%s", line);
                found++;
            }
        }
    return found;
}


