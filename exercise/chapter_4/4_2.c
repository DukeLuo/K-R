/* 练习 4-2 */

#include <ctype.h>
#include <math.h>
#include <stdio.h>

#define MAXLINE 100

int main(void)
{
    double atof2(char s[]);
	char s1[] = "87.549e2", s2[] = "-982.47e-3", s3[] = "-54e", s4[] = "-0.64E4";
    
	printf("s1 = %10s >> %15lf, real value: %15lf\n", s1, atof2(s1), atof(s1));
	printf("s2 = %10s >> %15lf, real value: %15lf\n", s2, atof2(s2), atof(s2));
	printf("s3 = %10s >> %15lf, real value: %15lf\n", s3, atof2(s3), atof(s3));
	printf("s4 = %10s >> %15lf, real value: %15lf\n", s4, atof2(s4), atof(s4));
	return 0;
}



double atof2(char s[])
{
    double val, power;
    int i, sign1, sign2, exp;
    
    for (i = 0; isspace(s[i]); ++i)
        ;
    sign1 = (s[i] == '-') ? -1 : 1;
    if (s[i] == '+' || s[i] == '-')
        ++i;
    for (val = 0.0; isdigit(s[i]); ++i)
        val = 10.0 * val + (s[i] - '0');
    if (s[i] == '.')
        ++i;
    for (power = 1.0; isdigit(s[i]); ++i) {
        val = 10.0 * val + (s[i] - '0');
        power *= 10.0;
    }
    
    if (s[i] == 'e' || s[i] == 'E')
        ++i;
    sign2 = (s[i] == '-') ? -1 : 1;
    if (s[i] == '+' || s[i] == '-')
        ++i;
    for (exp = 0; isdigit(s[i]); ++i)
        exp = 10 * exp + (s[i] - '0');
    
    return sign1 * val / power * pow(10, sign2*exp);
}

