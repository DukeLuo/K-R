/* 4.10 递归 */

#include <stdio.h>

void printd(int n)
{
    if (n < 0) {
        putchar('-');
        n = -n;
    }
    if (n / 10)
        printd(n / 10);
    putchar(n % 10 + '0');
}


/* qsort函数： 以递增顺序对v[left] ... v[right]进行排序 */
void qsort(int v[], int left, int right)
{
    int i, last;
    void swap(int v[], int i, int j);
    
    if (left >= right)
        return;
    swap(v, left, (left + right)/2);
    last = left;
    for (i = left+1; i <= right; ++i)
        if (v[i] < v[left])
            swap(v, ++last, i);
    swap(v, left, last);
    qsort(v, left, last-1);
    qsort(v, last+1, right);
}


void swap(int v[], int i, int j)
{
    int temp;
    
    temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}



int main(void)
{
    int i;
    int a[13] = {10, 1, 5, 6, 7, 85, 43, 57, 743, 568,354, 357, 23};
    
    for (i = 0; i < 13; ++i) {
        printd(a[i]);
        putchar(' ');
    }
    qsort(a, 0, 12);
    putchar('\n');
    for (i = 0; i < 13; ++i) {
        printd(a[i]);
        putchar(' ');
    }
    return 0;
}


    