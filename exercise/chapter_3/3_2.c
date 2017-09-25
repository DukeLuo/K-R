/* 练习 3-2 */

void escape(char s[], char t[])
{
    int i, j;
    
    i = j = 0;
    while (t[i] != '\0')
        switch (t[i]) {
            case '\a':
                s[j++] = '\\';
                s[j++] = 'a';
                ++i;
                break;
            case '\b':
                s[j++] = '\\';
                s[j++] = 'b';
                ++i;
                break;
            case '\f':
                s[j++] = '\\';
                s[j++] = 'f';
                ++i;
                break;
            case '\n':
                s[j++] = '\\';
                s[j++] = 'n';
                ++i;
                break;
            case '\r':
                s[j++] = '\\';
                s[j++] = 'r';
                ++i;
                break;
            case '\t':
                s[j++] = '\\';
                s[j++] = 't';
                ++i;
                break;
            case '\v':
                s[j++] = '\\';
                s[j++] = 'v';
                ++i;
                break;
            default:
                s[j++] = t[i];
                ++i;
                break;
        }
    s[j] = '\0';
}



void unescape(char s[], char t[])
{
    int i, j;
    
    i = j = 0;
    while (t[i] != '\0') {
        if (t[i] == '\\') {
            ++i;
            switch (t[i]) {
                case 'a':
                    s[j++] = '\a';
                    ++i;
                    break;
                case 'b':
                    s[j++] = '\b';
                    ++i;
                    break;
                case 'f':
                    s[j++] = '\f';
                    ++i;
                    break;
                case 'n':
                    s[j++] = '\n';
                    ++i;
                    break;
                case 'r':
                    s[j++] = '\r';
                    ++i;
                    break;
                case 't':
                    s[j++] = '\t';
                    ++i;
                    break;
                case 'v':
                    s[j++] = '\v';
                    ++i;
                    break;
                default:
                    s[j++] = '\\';
                    s[j++] = t[i];
                    ++i;
                    break;
            }
        }
        else {
            s[j++] = t[i];
            ++i;
        }
    }
    s[j] = '\0';
}



#include <stdio.h>

int main(void) {
    char text1[50] = "\aHello,\n\tWorld! Mistakee\b was \"Extra 'e'\"!\n";
    char text2[51];
    
    printf("Original string:\n%s\n", text1);
    
    escape(text2, text1);
    printf("Escaped string:\n%s\n", text2);
    
    unescape(text1, text2);
    printf("Unescaped string:\n%s\n", text1);
    
    return 0;
}
            
                