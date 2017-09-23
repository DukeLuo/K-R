/* 练习2-8 */

unsigned rightrot(unsigned x, int n)
{
    while(n > 0) {
        if (x & ~(~0U << 1)) // 判断x最右边的一位是0或者1
            x = (x >> 1) | ~(~0U >> 1);
        else
            x = (x >> 1);
        --n;
    }
    return x;
}

