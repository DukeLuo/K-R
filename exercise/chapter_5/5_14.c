/* 练习　5-14 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAXLINE 5000
#define NUMERIC 1   /* 按数值排序　*/
#define DECR 2      /* 按逆序排序　*/

char *lineptr[MAXLINE];

int readlines(char *lineptr[], int nlines);
void writelines(char *lineptr[], int nlines, int bit);

int numcmp(const char *s1, const char *s2);

void myqsort(void *lineptr[], int left, int right,
           int (*cmp)(void *, void *));

int main(int argc, char *argv[])
{
    int nlines;
    int c;
    int options = 0;    /* 模式控制位　*/

    while (--argc > 0 && (*++argv)[0] == '-')
        while (c = *++argv[0])
            switch (c) {
            case 'n':
                options |= NUMERIC;
                break;
            case 'r':
                options |= DECR;
                break;
            default:
                printf("find: illegal option %c\n", c);
                argc = 0;
                break;
        }
    if (argc) {
        printf("Usage: sort -n -r\n");
        return 1;
    }

    if ((nlines = readlines(lineptr, MAXLINE)) >= 0) {
        if (options & NUMERIC)
            myqsort((void **) lineptr, 0, nlines-1,
                    (int (*)(void*, void*))(numcmp));
        else
            myqsort((void **) lineptr, 0, nlines-1,
                    (int (*)(void*, void*))(strcmp));
        writelines(lineptr, nlines, options & DECR);
        return 0;
    }
    else {
    printf("error: input too big to sort\n");
    return 1;
    }
}


#define MAXLEN 1000
int mygetline(char *, int);
char *alloc(int);

/* readlines函数：　读取输入行　*/
int readlines(char *lineptr[], int maxlines)
{
    int len, nlines;
    char *p, line[MAXLEN];

    nlines = 0;
    while ((len = mygetline(line, MAXLEN)) > 0) {
        if (nlines >= maxlines || (p = alloc(len)) == NULL)
            return -1;
        else {
            line[len-1] = '\0';
            strcpy(p, line);
            lineptr[nlines++] = p;
        }
    }
    return nlines;
}


/* writelines函数：　写输入行　*/
/* bit为真值，逆序输出，否则顺序输出　*/
void writelines(char *lineptr[], int nlines, int bit)
{
    while (nlines-- > 0)
        printf("%s\n", bit ? lineptr[nlines] : *lineptr++);
}


/* myqsort函数：　按递增顺序对v[left]...v[right]进行排序　*/
void myqsort(void *v[], int left, int right,
           int (*comp)(void *, void *))
{
    int i, last;
    void swap(void *v[], int  i, int j);

    if (left >= right)
        return;
    swap(v, left, (left+right)/2);
    last = left;
    for (i = left+1; i <= right; i++) {
        if ((*comp)(v[i], v[left]) < 0)
            swap(v, ++last, i);
    }
    swap(v, left, last);
    myqsort(v, left, last-1, comp);
    myqsort(v, last+1, right, comp);
}



/* swap函数：　交换v[i]和v[j] */
void swap(void *v[], int i, int j)
{
    void *temp;

    temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}


/* numcmp函数：按数值顺序比较字符串s1和s2 */
int numcmp(const char *s1, const char *s2)
{
    double v1, v2;

    v1 = atof(s1);
    v2 = atof(s2);
    if (v1 < v2)
        return -1;
    else if (v1 > v2)
        return 1;
    else
        return 0;
}


