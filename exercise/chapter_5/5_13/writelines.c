/* writelines函数　*/

#include <stdio.h>

/* writelines函数：　写输入行　*/
void writelines(char *lineptr[], int nlines)
{
    while (nlines-- > 0)
        printf("%s\n", *lineptr++);
}


