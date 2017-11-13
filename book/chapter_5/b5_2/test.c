#include <stdio.h>

#define SIZE 5

int main(void)
{
    int n, array[SIZE];
    int getint(int *);

    for (n = 0; n < SIZE; ++n)  /*　将数组初始化为-66, 为了练习5-1有对比 */
        array[n] = -66;
    for (n = 0; n < SIZE && getint(&array[n]) != EOF; ++n)
        ;
    for (n = 0; n < SIZE; ++n)
        printf("%d: %d\n", n, array[n]);
    putchar('\n');
    return 0;
}


