/* 练习 4-4 */

#include <stdio.h>

#define MAXVAL 100        /* 栈val的最大深度 */

int sp = 0;               /* 下一个空闲栈位置 */
double val[MAXVAL];       /* 值栈 */

void push(double f)
{
    if (sp < MAXVAL)
        val[sp++] = f;
    else
        printf("error: stack full, can't push %g\n", f);
}


double pop(void)
{
    if (sp > 0)
        return val[--sp];
    else {
        printf("error: stack empty\n");
        return 0.0;
    }
}


void showTop(void)
{
    sp > 0 ? printf("\t%.8g\n", val[sp-1]) : printf("error: stack empty\n");
}


void duplicateTop(void)
{
    double temp;
    
    if (sp > 0)
        if (sp > MAXVAL - 1)
            printf("error: stack full\n");
        else {
            temp = pop();
            push(temp);
            push(temp);
        }
    else
        printf("error: stack empty\n");
}


void swapTop(void)
{
    double temp;
    
    if (sp < 1)
        printf("error: stack has less than 2 elements\n");
    else
    {
        temp = val[sp-1];
        val[sp-1] = val[sp-2];
        val[sp-2] = temp;
    }    
}


void clear(void)
{
    sp = 0;
}

