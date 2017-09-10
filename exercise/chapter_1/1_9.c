#include <stdio.h>
#define NONBLANK 'a'

/* 练习1-9 */
int main()
{
    int c, lastc;
    
    lastc = NONBLANK;
    while ((c = getchar()) != EOF) {
        if (c != ' ')
            putchar(c);
        else if (lastc != ' ')
            putchar(c);
        lastc = c;
    }
}



#include <stdio.h>

int main()
{
    int c, inspace;
    
    inspace = 0;
    while ((c = getchar()) != EOF) {
        if (c == ' ') {
            if (inspace == 0) {
                inspace = 1;
                putchar(c);
            }
        }
        else {
            inspace = 0;
            putchar(c);
        }
    }
}

   