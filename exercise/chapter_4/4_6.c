/* 练习 4-6 */

/* 可以使用A~Z之间字母作为变量名，支持上题拓展的库函数
操作，用#可以使用储存的上次计算结果 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
#include <string.h>
#include "calc.h"

#define MAXOP 100
#define IDENTIFIER 300
#define VARIABLE 301

void mathfuc(char s[]);

int main(void)
{
    int type, var;
    int i;
    int assigning;
    double op2;
    double v;
    char s[MAXOP];
    double variable[26];

/*****************************************************************/    
    var = 0;
    for(i = 0; i < 26; ++i)
        variable[i] = 0.0;
    while ((type = getop(s)) != EOF) {
        //printf("type: %d\n", type);
        switch (type) {
            case NUMBER:
                assigning = 0;
                push(atof(s));
                break;
            case IDENTIFIER:
                mathfuc(s);
                break;
            case VARIABLE:
                push(variable[s[0]-'A']);       //变量的值
                var = s[0];                     //记录变量名
                break;
            case '+':
                assigning = 0;
                push(pop() + pop());
                break;
            case '*':
                assigning = 0;
                push(pop() * pop());
                break;
            case '-':
                assigning = 0;
                op2 = pop();
                push(pop() - op2);
                break;
            case '/':
                assigning = 0;
                op2 = pop();
                if (op2 != 0.0)
                    push(pop() / op2);
                else
                    printf("error: zero divisor\n");
                break;
            case '=':
                assigning = 1;
                pop();
                if (var >= 'A' && var <= 'Z')
                    variable[var-'A'] = pop();
                else
                    printf("error: no variable name %d\n", var);
                break;
            case '\n':      //正在赋值操作，不打印
                if (!assigning) {
                    v = pop();
                    printf("\t%.8g\n", v);
                }
                break;
            case '#':       //存储上次计算结果
                assigning = 0;
                push(v);
                break;
            default:
                printf("error: unknown command %s\n", s);
                break;
        }
/******************************************************************/
    }
    return 0;
}


void mathfuc(char s[])
{
    double op2;
    
    if (strcmp(s, "sin") == 0)
        push(sin(pop()));
    else if (strcmp(s, "cos") == 0)
        push(cos(pop()));
    else if (strcmp(s, "exp") == 0)
        push(exp(pop()));
    else if (strcmp(s, "pow") == 0) {
        op2 = pop();
        push(pow(pop(), op2));
    }
    else 
        printf("error: unknown command %s\n", s);
}


/* getop函数： 获取下一个运算符或数值操作数 */
int getop(char s[])
{   
    int i, c;
    
    while ((s[0] = c = getch()) == ' ' || c == '\t')
        ;
    s[1] = '\0';
/**********************************************************************/
    if (!isdigit(c) && !isalpha(c) && c != '.' && c != '-')
        return c;
    i = 0;
    if (isalpha(c)) {
        if (isupper(c)) {
            s[0] = c;
            s[1] = '\0';
            return VARIABLE;
        }
        else {
            while (islower(s[++i] = c = getch()))
                ;
            s[i] = '\0';
            if (c != EOF)
                ungetch(c);
            return IDENTIFIER;
        }
    }
/**********************************************************************/
    if (c == '-') {
        if (isdigit(c=getch()) || c == '.')
            s[++i] = c;
        else {
            if (c != EOF)
                ungetch(c);
            return '-';
        }
    }    
    if (isdigit(c))
        while (isdigit(s[++i] = c = getch()))
            ;
    if (c == '.')
        while (isdigit(s[++i] = c = getch()))
            ;
    s[i] = '\0';
    if (c != EOF)
        ungetch(c);
    return NUMBER;
}

