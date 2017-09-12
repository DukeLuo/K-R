/* 练习 1-13 */

#include <stdio.h>

#define IN 1
#define OUT 0
#define MAX_AXIS_LENGTH 10
#define MAX_HISTOGRAM_LENGTH 66
#define MAX_WORD_LENGTH MAX_AXIS_LENGTH - 1

int main()
{
    int i, c, nc, state;
    int wl[MAX_AXIS_LENGTH + 1];
    int j;
    int maxnum;     // 记录的最大个数
    int nh;     // 打印水平直方图时打印*的个数
    int nv;     // 打印垂直直方图时打印的行数
    int unit;
    
    state = OUT;
    nc = 0;
    for(i = 1; i <= MAX_AXIS_LENGTH; i++)
        wl[i] = 0;
    
    /* 统计各长度单词的数目 */
    while((c =getchar()) != EOF) {
        if(c == ' ' || c == '\n' || c == '\t') {
            if (state == IN) {
                if (nc > MAX_WORD_LENGTH)
                    wl[MAX_AXIS_LENGTH]++;
                else
                    wl[nc]++;
            }
            state = OUT;
            nc = 0;
            }
        else {
            ++nc;
            state = IN;
        }
    }
    
    maxnum = nh = 0;
    for(i = 1; i <=MAX_AXIS_LENGTH; i++) {
        if(wl[i] > maxnum)
            maxnum = wl[i];
    }
    unit = MAX_HISTOGRAM_LENGTH / maxnum;
    
    /* 画水平方向直方图 */
    for(i = 1; i <= MAX_AXIS_LENGTH; i++) {
        nh = wl[i] * unit;
        if (i == MAX_AXIS_LENGTH)
            printf("OVERFLOW");
        else 
            printf("%d  WORDS", i);
        for(j = nh; j > 0; j--)
            printf(" *");
        printf("   %d\n", wl[i]);
    }
    
    putchar('\n');
    
    /* 画垂直方向直方图 */
    for(i = 1; i <= MAX_AXIS_LENGTH; i++) 
        wl[i] = wl[i] * unit;
    nv = MAX_HISTOGRAM_LENGTH + 1;  // 在直方图上以便显示数据
    for(i = nv; i > 0; i--) {
        putchar('\t');
        for(j = 1; j <= MAX_AXIS_LENGTH; j++) {
            if(wl[j] == i) {
                printf("*******\t");
                wl[j]--;
            }
            else if(wl[j] == i - 1)
                printf("   %d  \t", wl[j] / unit);
            else
                printf("       \t");
        }
        putchar('\n');
    }
    /* 打印垂直方向直方图坐标轴 */
    putchar('\t');
    for(i = 1; i <= MAX_AXIS_LENGTH; i++)
        if(i == MAX_AXIS_LENGTH)
            printf("OVERFLOW\t");
        else
            printf("%d WORDS\t", i);
}

     