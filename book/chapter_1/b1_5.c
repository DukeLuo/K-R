/* 1.5 字符输入/输出 */


/* 1.5.1 文件复制 */

#include <stdio.h>

int main()
{
    int c;
    
    c=getchar();
    while (c != EOF) {
        putchar(c);
        c =getchar();
    }
}

#include <stdio.h>

int main()
{
    int c;
    while ((c = getchar()) != EOF )
        putchar(c);
}



/* 1.5.2 字符计数 */

#include <stdio.h>

int main()
{
    long nc;
    
    nc = 0;
    while (getchar() != EOF)
        ++nc;
    printf("%ld\n",nc);
}

#include <stdio.h>

int main()
{
    double nc;
    
    for (nc = 0; getchar() != EOF; ++nc)
        ;
    printf("%0.f\n", nc);
}



/* 1.5.3 行计数 */
#include <stdio.h>

int main()
{
    int c, nl;
    
    nl = 0;
    while ((c = getchar()) != EOF)
        if (c == '\n')
            ++nl;
    printf("%d\n",nl);
}



/* 单词计数 */
#include <stdio.h>

#define IN 1
#define OUT 0

int main()
{
    int c, nl, nw, nc, state;
    
    state = OUT;
    nl = nw = nc = 0;
    while((c = getchar()) != EOF) {
        ++nc;
        if (c == '\n')
            ++nl;
        if (c == ' ' || c == '\n' || c == '\t')
            state = OUT;
        else if (state == OUT) {
            state = IN;
            ++nw;
        }
    }
    printf("%d %d %d\n", nl, nw, nc);
}

