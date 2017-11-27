/*　6.5 自引用结构 */

#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

#define MAXWORD 100

struct tnode {
    char *word;
    int count;
    struct tnode *left;
    struct tnode *right;
};

struct tnode *addtree(struct tnode *, char *);
void treeprint(struct tnode *);
int getword(char *, int);

struct tnode *talloc(void);

/* 单词出现频率的统计　*/
int main(void)
{
    struct tnode *root;
    char word[MAXWORD];

    root = NULL;
    while (getword(word, MAXWORD) != EOF)
        if (isalpha(word[0]))
            root = addtree(root, word);
    treeprint(root);
    return 0;
}


/* addtree函数：　在p的位置或p的下方增加一个w节点　*/
struct tnode *addtree(struct tnode *p, char *w)
{
    int cond;

    if (p == NULL) {        /* 该单词是一个新单词　*/
        p = talloc();
        p->word = strdup(w);
        p->count = 1;
        p->left = p->right = NULL;
    } else if ((cond = strcmp(w, p->word)) == 0)
        p->count++;
    else if (cond < 0)      /* 如果小于该节点中的单词，则进入左子树　*/
        p->left = addtree(p->left, w);
    else                    /* 如果大于该节点中的单词，则进入右子树　*/
        p->right = addtree(p->right, w);
    return p;
}


/* treeprint函数：　按序打印树p */
void treeprint(struct tnode *p)
{
    if (p != NULL) {
        treeprint(p->left);
        printf("%4d %s\n", p->count, p->word);
        treeprint(p->right);
    }
}


/* talloc函数：　创建一个tnode */
struct tnode *talloc(void)
{
    return (struct tnode *) malloc(sizeof(struct tnode));
}


/* getword函数：　从输入中读取下一个单词或字符　*/
int getword(char *word, int lim)
{
    int c;
    char *w = word;
    int getch(void);
    void ungetch(int);

    while (isspace(c=getch()))
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


