/* 指针数组以及指向指针的指针　*/
/* 按字母顺序对文本行集合排序　*/

#include <stdio.h>
#include <string.h>

#define MAXLINE 5000

char *lineptr[MAXLINE];

int readlines(char *lineptr[], int nlines);
void writelines(char *lineptr[], int nlines);
void qsort(char *lineptr[], int left, int right);

int main(void)
{
    int nlines;
    char s[5000];

    if ((nlines = readlines(lineptr, MAXLINE)) >= 0) {
        qsort(lineptr, 0, nlines -1);
        writelines(lineptr, nlines);
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
void writelines(char *lineptr[], int nlines)
{
    while (nlines-- > 0)
        printf("%s\n", *lineptr++);
}


/* qsort函数：　按递增顺序对v[left]...v[right]进行排序　*/
void qsort(char *v[], int left, int right)
{
    int i, last;
    void swap(char *v[], int  i, int j);

    if (left >= right)
        return;
    swap(v, left, (left+right)/2);
    last = left;
    for (i = left+1; i <= right; i++) {
        if (strcmp(v[i], v[left]) < 0)
            swap(v, ++last, i);
    }
    swap(v, left, last);
    qsort(v, left, last-1);
    qsort(v, last+1, right);
}



/* swap函数：　交换v[i]和v[j] */
void swap(char *v[], int i, int j)
{
    char *temp;

    temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}


