/* 练习　6-2 */
/* 将二叉树转化为一个结构列表，然后按要求比较　*/

#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

#define MAXWORD 100
#define MAX_LIST_LEN 1000       /* 列表的长度　*/

struct tnode {
    char *word;
    int count;
    struct tnode *left;
    struct tnode *right;
};

struct lelement{        /* 列表元素　*/
    char *word;
    int count;
};

struct tnode *addtree(struct tnode *, char *);
void treeprint(struct tnode *);
int getword(char *, int);

struct tnode *talloc(void);



static struct lelement nodelist[MAX_LIST_LEN];
static struct lelement *ptr = nodelist;

/* next函数：　获得nodelist的下一位置　*/
struct lelement *next(void)
{
    if (ptr < nodelist + MAX_LIST_LEN)
        return ptr++;
    else 
        return NULL;
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


/* talloc函数：　创建一个tnode */
struct tnode *talloc(void)
{
    return (struct tnode *) malloc(sizeof(struct tnode));
}


/* treetolist函数：　将树摊平为一个列表　*/
void treetolist(struct tnode *p)
{
    struct lelement *i;

    if (p != NULL) {
        treetolist(p->left);
        if ((i = next()) != NULL) {
            i->word = p->word;
            i->count = p->count;
        }
        treetolist(p->right);
    }
}


/* listprint函数：　按要求打印列表nodelist */
void listprint(struct lelement *p, int n, int i)
{
    char *s = NULL;

    while (n--) 
        if (s == NULL) {        /* 第一个字符不比较　*/
            printf("%4d %s", p->count, p->word);
            s = p->word;
            ++p;
        } else {
            printf("%c", (strncmp(p->word, s, i) == 0) ? '\t' : '\n');
            printf("%4d %s", p->count, p->word);
            s = p->word;
            ++p;
        }
    putchar('\n');
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
    if (!isalpha(c) && c != '_' && c != '#') {
        if (c == '"') {
            while (--lim)
                if ((*w++ = getch()) == '"') {
                    *w = '\0';
                    return word[0];
                }
        } else if (c == '/') {
            if ((c = getch()) == '/')       //行注释
                while ((c = getch()) != '\n')
                    ;
            else                            //段注释
                while ((c = getch()) != '/')
                    ;
            *w = '\0';
            return '/';
        } else {
            *w = '\0';
            return c;
        }
    }
    while (--lim > 0)
        if (isalnum(c = getch()) || c == '_' || c == '#')
            *w++ = c;
        else {
            ungetch(c);
            break;
        }
    *w = '\0';
    return word[0];
}



/* 单词出现频率的统计　*/
int main(int argc, char *argv[])
{
    int nchar = 6;          /* 指定比较前６个字符　*/
    struct tnode *root;
    char word[MAXWORD];

    if (argc == 2)
        nchar = atoi(argv[1]);
    else if (argc == 1)
        ;
    else
        return 1;

    root = NULL;
    while (getword(word, MAXWORD) != EOF)
        if (isalpha(word[0]))
            root = addtree(root, word);
    treetolist(root);
    listprint(nodelist, ptr-nodelist, nchar);
    return 0;
}


