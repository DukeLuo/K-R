/* 练习 4-9 */

/* 我们知道EOF的值为-1，int类型至少为16位，
我们声明的buf数组是字符数组，char类型只有8位，
因此在储存的时候，需要转换，会丢弃高八位。
字符数组不能很好地处理负数，因此，我们将buf
声明为int类型。 */

#include <stdio.h>

#define BUFSIZE 100

int buf[BUFSIZE];     /* 用于ungetch函数的缓冲区 */
int bufp = 0;          /* buf中下一个空闲的位置 */

int getch(void)
{
    return (bufp > 0) ? buf[--bufp] : getchar();
}


void ungetch(int c)
{
    if (bufp >= BUFSIZE)
        printf("ungetch: too many characters\n");
    else
        buf[bufp++] = c;
}

