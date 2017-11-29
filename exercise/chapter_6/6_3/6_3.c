/*　练习　6-3 */

#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

#define MAXWORD 100

struct linklist {
    int lnum;
    struct linklist *ptr;
};

struct tnode {
    char *word;
    struct linklist *lines;
    struct tnode *left;
    struct tnode *right;
};

struct tnode *addtree(struct tnode *, char *, int n);
void treeprint(struct tnode *);
int getword(char *, int);
int isnoiseword(char *);

struct tnode *talloc(void);
struct linklist *lalloc(void);


/* talloc函数：　创建一个tnode */
struct tnode *talloc(void)
{
    return (struct tnode *) malloc(sizeof(struct tnode));
}


/* lalloc函数：　创建一个linklist */
struct linklist *lalloc(void)
{
    struct linklist *l;

    l = malloc(sizeof(struct linklist));
    l->ptr = NULL;
    return l;
}


/* addtree函数：　在p的位置或p的下方增加一个w节点　*/
struct tnode *addtree(struct tnode *p, char *w, int n)
{
    int cond;
    struct linklist *i, *l;

    if (p == NULL) {        /* 该单词是一个新单词　*/
        p = talloc();
        l = lalloc();
        l->lnum = n;
        p->word = strdup(w);
        p->lines = l;
        p->left = p->right = NULL;
    } else if ((cond = strcmp(w, p->word)) == 0) {
        l = lalloc();
        l->lnum = n;
        i = p->lines;
        for ( ; i->ptr != NULL; i = i->ptr)
            ;
        i->ptr = l;
    } else if (cond < 0)      /* 如果小于该节点中的单词，则进入左子树　*/
        p->left = addtree(p->left, w, n);
    else                    /* 如果大于该节点中的单词，则进入右子树　*/
        p->right = addtree(p->right, w, n);
    return p;
}


/* treeprint函数：　按序打印树p */
void treeprint(struct tnode *p)
{
    struct linklist *i;

    if (p != NULL) {
        treeprint(p->left);
        printf("%s\t", p->word);
        i = p->lines;
        while (i != NULL) {
            printf("%6d", i->lnum);
            i = i->ptr;
        }
        putchar('\n');
        treeprint(p->right);
    }
}


/* getword函数：　从输入中读取下一个单词或字符　*/
int getword(char *word, int lim)
{
    int c;
    char *w = word;
    int getch(void);
    void ungetch(int);

    while (isspace(c=getch()) && c != '\n')     /*　使getword可以读取换行符　*/
        ;
    if (c != EOF)
        *w++ = c;
    if (!isalpha(c)) {
        *w = '\0';
        return c;
    }
    for (; --lim > 0; w++)
        if (!isalpha(*w=getch())) {
            ungetch(*w);
            break;
        }
    *w = '\0';
    return word[0];
}


/* isnoiseword函数：　判断是否是非实义单词　*/
int isnoiseword(char *word)
{
    static char *nw[] = {
        NULL,
        "a",
        "an",
        "and",
        "are",
        "in",
        "is",
        "of",
        "or",
        "that",
        "the",
        "this",
        "to"
    };
    int cond;
    int low, high, mid;

    low = 1;
    high = (sizeof nw / sizeof nw[0]) - 1;
    while ( low <= high) {
        mid = (low+high) / 2;
        if ((cond = strcmp(word, nw[mid])) < 0)
            high = mid -1;
        else if (cond > 0)
            low = mid + 1;
        else
            return mid;
    }
    return -1;
}



/* 单词出现频率的统计　*/
int main(void)
{
    struct tnode *root;
    char word[MAXWORD];
    int nlines = 1;

    root = NULL;
    while (getword(word, MAXWORD) != EOF)
        if (isalpha(word[0]) && isnoiseword(word) == -1)
            root = addtree(root, word, nlines);
        else if (word[0] == '\n')
            nlines++;
    treeprint(root);
    return 0;
}


