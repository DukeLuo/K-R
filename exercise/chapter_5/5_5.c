/* 练习　5-5 */

#include <stdio.h>

#define SIZE 10000

void strncpy0(char *s, char *t, int n)
{
    while ((*s++ = *t++)) {
        --n;
        if (n == 0) {
            *s = '\0';
            break;
        }
    }
}

void strncat0(char *s, char *t, int n)
{
    while (*s++)
        ;
    --s;
    while ((*s++ = *t++)) {
        --n;
        if (n == 0) {
            *s = '\0';
            break;
        }
    }
}

int strncmp0(char *s, char *t, int n)
{
    for (; (*s == *t) && (n > 0); ++s, ++t) {
        --n;
        if (*s == '\0')
            return 0;
    }
    return *s - *t;
}


int main(void)
{
	char s[SIZE] = "Aomine Daiki";
    char t[SIZE] = "Kise Ryota";
    char u[SIZE];
    char v[SIZE];
	char *ps =  "Aomine Daiki";
    char *pt = "Kise Ryota";
    char *pu = "";
    char *pv = "";

	printf("strncmp0(%s, %s, %d) = %d\n", ps, pt, 10, strncmp0(s, t, 10));
    printf("strncmp0(%s, %s, %d) = %d\n", pt, ps, 10, strncmp0(t, s, 10));
    printf("strncmp0(%s, %s, %d) = %d\n", pt, pt, 10, strncmp0(t, t, 10));
    printf("strncmp0(%s, %s, %d) = %d\n", ps, pt, 100, strncmp0(s, t, 100));
    
    strncat0(s, t, 8);
	printf("strncat0(%s, %s, %d) = %s\n", ps, pt, 8, s);
    strncat0(s, t, 80);
	printf("strncat0(%s, %s, %d) = %s\n", ps, pt, 80, s);

    strncpy0(u, t, 6);
	printf("strncpy0(%s, %s, %d) = %s\n", pu, pt, 6, u);
    strncpy0(v, t, 60);
	printf("strncpy0(%s, %s, %d) = %s\n", pv, pt, 60, v);	
	return 0;
}
        

