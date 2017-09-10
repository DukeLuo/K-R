#include <stdio.h>

/* 练习1-6 */
int main()
{
    int c;
    
    while ((c = getchar() != EOF)) 
        printf ("%d\n",c);
    printf ("%d - at EOF\n",c);
}
        
        