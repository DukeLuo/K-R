/* 练习 4-7 */

#include <stdio.h>
#include <string.h>

#define BUFSIZE 100

char buf[BUFSIZE];     /* 用于ungetch函数的缓冲区 */
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


void ungets(char s[])
{
    int len;
    void ungetch(int);
    
    len = strlen(s);
    while (len > 0)
        ungetch(s[--len]);
}



int main(void)
{
	char s[] = "Rapa chika paka, raja babu\n";
	int c;
	ungets(s);
    
	while((c = getch()) != EOF)
		putchar(c);
	return 0;
}

