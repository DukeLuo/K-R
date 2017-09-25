/* 练习 3-6 */

#include <stdio.h>
#include <string.h>

#define abs(x) ((x) < 0 ? -(x) : (x))

void itoa(int n, char s[], int d);
void reverse(char s[]);

int main(void)
{
	char s[100];
	
	for (int i = -50; i <= 50; i++) {
		itoa(i, s, 8);
		printf("%s : %4d\n", s, i);
	}
	return 0;
}



void itoa(int n, char s[], int d)
{
    int i, sign;
    
    sign = n;
    i = 0;
    do {
        s[i++] = abs(n % 10) + '0';
    } while ((n /= 10) != 0);
    if (sign < 0)
        s[i++] = '-';
    
    while (i < d)
        s[i++] = ' ';
    s[i] = '\0';
    reverse(s);
}


void reverse(char s[])
{
    int c, i, j;
    
    for(i = 0, j = strlen(s)-1; i < j; ++i, --j)
        c = s[i], s[i] = s[j], s[j] = c;
}

