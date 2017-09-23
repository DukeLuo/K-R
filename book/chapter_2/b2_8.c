/* 2.8 自增运算符与自减运算符 */

#include <stdio.h>

void squeeze(char s[], int c);
void strcat1(char s[], char t[]);

int main(void)
{
    char s[] = "abcde";
    char t[] = "12345";
    
    squeeze(s, 'a');
    printf("%s\n", s);
    squeeze(s, 'b');
    printf("%s\n", s);
    squeeze(s, 'f');
    printf("%s\n", s);
    
    strcat1(s, t);
    printf("%s\n", s);
    strcat1(s, "3");
    printf("%s\n", s);
    strcat1(s, "");
    printf("%s\n", s);
    return 0;
}
    
    
    
    
    
    
void squeeze(char s[], int c)
{
    int i, j;
    
    for(i = j = 0; s[i] != '\0'; i++)
        if (s[i] != c)
            s[j++] = s[i];
    s[j] = '\0';
}

void strcat1(char s[], char t[])
{
    int i,j;
    
    i = j = 0;
    while(s[i] != '\0')
        i++;
    while ((s[i++] = t[j++]) != '\0')
        ;
}