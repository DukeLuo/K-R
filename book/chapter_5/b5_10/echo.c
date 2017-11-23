/* 5.10 命令行参数　*/
/* echo函数：　回显程序命令行参数　*/

#include <stdio.h>

int main(int argc, char *argv[])
{
    while (--argc > 0)
        printf("%s%s", *++argv, (argc > 1) ? " " : "");
    printf("\n");
    return 0;
}


