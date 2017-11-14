/*　练习　5-4 */

#include <stdio.h>
#include <string.h>

int strend(char *s, char *t)
{
    s = s + strlen(s) - strlen(t);
    for ( ; *s == *t; ++s, ++t)
        if (*t == '\0')
            return 1;
    return 0;
}


int main(void)
{
    char *s1 = "some really long string.";
    char *s2 = "ng.";
    char *s3 = "ng";

    if(strend(s1, s2))
    {
      printf("The string (%s) has (%s) at the end.\n", s1, s2);
    }
    else
    {
      printf("The string (%s) doesn't have (%s) at the end.\n", s1, s2);
    }
    if(strend(s1, s3))
    {
      printf("The string (%s) has (%s) at the end.\n", s1, s3);
    }
    else
    {
      printf("The string (%s) doesn't have (%s) at the end.\n", s1, s3);
    }
    return 0;
}


