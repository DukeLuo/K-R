/* 练习 1-15 */

#include <stdio.h>

float fahrtocelsius(float n);
int main()
{
    int lower, upper, step;
    int i;
    
    lower = 0;
    upper = 300;
    step = 20;
    
    for(i = lower; i <= upper; i = i + step)
        printf("%3d %6.1f\n", i, fahrtocelsius(i));
    return 0;
}

float fahrtocelsius(float fahr)
{
    float celsius;
    
    celsius = (5.0/9.0) * (fahr - 32.0);
    return celsius;
}

