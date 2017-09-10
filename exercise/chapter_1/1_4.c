#include <stdio.h>

/* 练习1-4 */
int main()
{
    float fahr, celsius;
    int lower, upper, step;
    
    lower = -20;
    upper = 100;
    step = 10;
    
    printf("℃-℉转换表\n");
    
    celsius = lower;
    while (celsius <= upper) {
        fahr = (9.0 /5.0) * celsius + 32.0;
        printf("%3.0f %6.1f\n", celsius, fahr);
        celsius = celsius + step;
    }
}

