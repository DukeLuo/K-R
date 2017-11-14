/* 练习 5-3　*/

#include <stdio.h>

void strcat(char *s, char *t)
{
    while (*s++)
        ;
    --s;
    while ((*s++ = *t++))
        ;
}


int main(void)
{
    void strcat(char *s, char *t);
    char S1[8192] = "String One";
    char S2[8192] = "";
    char S3[8192] = "String Three";


    printf("String one is (%s)\n", S1);
    printf("String two is (%s)\n", S2);
    printf("String three is (%s)\n", S3);
 
    strcat(S1, S2);
    strcat(S1, S3);
    printf("The combined string is (%s)\n", S1);

    return 0;
}


