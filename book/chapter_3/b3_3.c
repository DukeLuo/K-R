/* 3.3 else-if 语句 */

int binsearch(int x, int v[], int n)
{
    int low, high, mid;
    
    low = 0;
    high = n - 1;
    while (low <= high) {
        mid = (low+high) / 2;
        if (x < v[mid])
            high = mid - 1;
        else if (x > v[mid])
            low = mid + 1;
        else 
            return mid;
    }
    return -1;
}

#include <stdio.h>

int main(void)
{
    int num[] = {1,2,3,4,5,6,7,8,9};
    
    printf("%d\n", binsearch(3, num, 9));
    printf("%d\n", binsearch(10, num, 9));
    printf("%d\n", binsearch(9, num, 9));
    return 0;
}
    