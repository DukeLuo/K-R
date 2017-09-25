/* 3.5 while循环和for循环 */

#include <stdio.h>
#include <ctype.h>
#include <string.h>

int atoi(char s[])
{
    int i, n, sign;
    
    for (i = 0; isspace(s[i]); i++)
        ;
    sign = (s[i] == '-') ? -1 : 1;
    if (s[i] == '+' || s[i] == '-')
        ++i;
    for (n = 0; isdigit(s[i]); i++)
        n = 10 * n + (s[i] - '0');
    return sign * n;
}


void shellsort(int v[], int n)
{
    int gap, i, j, temp;
    
    for (gap = n/2; gap > 0; gap /= 2)
        for(i = gap; i < n; i++)
            for(j = i - gap; j >= 0 && v[j] > v[j+gap]; j -= gap) {
                temp = v[j];
                v[j] = v[j+gap];
                v[j+gap] = temp;
            }
}


void reverse(char s[])
{
    int c, i, j;
    
    for(i = 0, j = strlen(s)-1; i < j; ++i, --j)
        c = s[i], s[i] = s[j], s[j] = c;
}
                

int main(void)
{
    int i;
    int s[] = {9, 8, 7, 6, 0, 4, 3, 0, 1, 0};
    char t[] = "hello, world";
    shellsort(s, 10);
    for (i = 0; i < 10; i++)
        printf("%2d%c", s[i], (i%10==9 || i==9) ? '\n' : ' ');
    
    reverse(t);
    for (i = 0; i < strlen(t); i++)
        printf("%c", t[i]);
    return 0;
}

