/* 练习 4-12 */

#include <stdio.h>
#include <limits.h>

int abs(int n)
{
    return (n >= 0) ? n : -n;
}


void itoa(int n, char s[])
{
    int abs(int i);
    static int i;
    static int sign = 1;
    
    if (n < 0)
        sign = 0;
    if (n / 10)
        itoa(abs(n/10), s);
    else {
        i = 0;
        if (sign == 0)
            s[i++] = '-';
    }
    s[i++] = abs(n) % 10 + '0';
    s[i] = '\0';
}



int main(void)
{
    int array[22] =
    {   0,
        1,
        2,
        9,
        10,
        11,
        16,
        17,
        21,
        312,
        -0,
        -1,
        -2,
        -9,
        -10,
        -11,
        -16,
        -17,
        -21,
        -312,
        INT_MAX,
        INT_MIN,
        };
    int i;
    char s[100];

    for (i = 0; i < 22; ++i)
    {
        itoa(array[i], s);
        printf("%d    %s\n", array[i], s);
    }
    return 0;
}

        