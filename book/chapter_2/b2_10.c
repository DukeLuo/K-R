/* 赋值运算符与表达式 */
#include <stdio.h>
int bitcount(unsigned x)
{
    int b;
    for(b = 0; x != 0; x >>= 1)
        if (x & 01)
            b++;
    return b;
}

