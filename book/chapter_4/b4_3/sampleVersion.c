#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
#include <string.h>
#include "calc.h"

#define MAXOP 100
#define IDENTIFIER 'i'

int main(void)
{
    int type;
    int i, var;
    int assigning;
    double op2;
    double v;
    char s[MAXOP];
    double variable[26];
    
    var = 0;
    for(i = 0; i < 26; ++i)
        variable[i] = 0.0;
    while ((type = getop(s)) != EOF) {
        switch (type) {
            case NUMBER:
                assigning = 0;
                push(atof(s));
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
/*******************************************************************/
            case '=':
                assigning = 1;
                pop();
                if (var >= 'A' && var <= 'Z')
                    variable[var-'A'] = pop();
                else
                    printf("error: no variable name %d\n", var);
                break;
            case '\n':
                if (!assigning) {
                    v = pop();
                    printf("\t%.8g\n", v);
                }
                break;
            default:
                if (type >= 'A' && type <= 'Z')
                    push(variable[type-'A']);
                else if (type == 'v')
                    push(v);
                else 
                    printf("error: unknown command %s\n", s);
                break;
        }
        var = type;
/******************************************************************/
    }
    return 0;
}
