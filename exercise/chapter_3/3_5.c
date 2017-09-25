/* 练习 3-5 */

#include <stdio.h>
#include <string.h>

#define abs(x) ((x) < 0 ? -(x) : (x))

void itob(int n, char s[], int b);
void reverse(char s[]);

int main(void)
{
	char s[100];
	
	for (int i = 2; i <= 20; i++) {
		itob(255, s, i);
		printf("decimal 255 in base %-2d : %s\n", i, s);
	}
	
	return 0;
}



void itob(int n, char s[], int b)
{
    int i, sign, c;
    
    sign = n;
    i = 0;
    do {
        c = abs(n%b);
        s[i++] = (c > 9) ? (c - 10 + 'A') : (c + '0');
    } while ((n /= b) != 0);
    if (sign < 0)
        s[i++] = '-';
    s[i] = '\0';
    reverse(s);
}


void reverse(char s[])
{
    int c, i, j;
    
    for(i = 0, j = strlen(s)-1; i < j; ++i, --j)
        c = s[i], s[i] = s[j], s[j] = c;
}

