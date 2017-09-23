/* 练习 2-6 */

unsigned setbits(unsigned x, int p, int n, unsigned y)
{
    return (x & ~(~(~0U << n) << (p+1-n))) |
           (y & ~(~0U << n) << (p+1-n));
}


