/* 练习 1-14 */

#include <stdio.h>
#include <ctype.h>

#define MAXCHARS 128
#define MAX_HISTOGRAM_LENGTH 66

int main()
{
    int c, i, j;
    int nchar[MAXCHARS];
    int maxnum, unit;
    int nh;
    
    for(i = 0; i < MAXCHARS; i++) 
        nchar[i] = 0;
    
    while((c = getchar()) != EOF) {
        if (c < MAXCHARS)
            nchar[c]++;
    }
    
    maxnum = 0;
    for(i = 0; i < MAXCHARS; i++) {
        if (nchar[i] > maxnum)
            maxnum = nchar[i];
    }
    unit = MAX_HISTOGRAM_LENGTH / maxnum;
    
    for(i = 1; i <= MAXCHARS; i++) {
        nh = nchar[i] * unit;
        if(isprint(i))
            printf("%c - %4d: ",i,i);
        else 
            printf("%8d: ",i);
        for(j = nh; j > 0; j--)
            printf(" *");
        printf("   %d\n", nchar[i]);
    }
}

   