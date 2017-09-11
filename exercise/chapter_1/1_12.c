#include <stdio.h>

#define IN 1
#define OUT 0

/* 练习 1-12 */
int main()
{
    int c, current_state, last_state;
    
    current_state = OUT;
    while ((c = getchar()) != EOF) {
        if (c == ' ' || c == '\n' || c == '\t') {
            if (last_state == IN)
                putchar('\n');
            current_state = OUT;
            last_state = current_state;
        }
        else if (current_state == OUT) {
            putchar(c);
            current_state = IN;
            last_state = current_state;
        }
        else {
            putchar(c);
            last_state = current_state;
        }
    }
}

            