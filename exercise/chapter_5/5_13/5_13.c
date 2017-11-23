/* 练习　5-13 */

#include <stdlib.h>
#include <stdio.h>

#define MAXLINES 5000
#define MAX_LASTLINES 100

char *lineptr[MAXLINES];

int readlines(char *lineptr[], int nlines);
void writelines(char *lineptr[], int nlines);

/* tail函数　*/
int main(int argc, char *argv[])
{
    int n = 10; //默认值是10，可通过可选参数改变
    int nlines;
    int i;
    char *lastlines[MAX_LASTLINES];

    if (argc == 1)
        ;
    else if (argc == 2 && argv[1][0] == '-')
        n = atoi(argv[1]+1);
    else {
        printf("Usage: print the last n lines of input\n");
        return 1;
    }

    if ((nlines = readlines(lineptr, MAXLINES)) >= 0) {
        if (n <= MAX_LASTLINES) {
            for ( i = 0; i < n; ++i) 
                lastlines[i] = lineptr[--nlines];
            writelines(lastlines, n);
            return 0;
        }
        else {
            printf("error: no enough space to storage the last n lines appointed\n");
            return 1;
        } 
    } else {
        printf("error: input too big to sort\n");
        return 1;
    }
}


