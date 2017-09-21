/* 练习 2-2 */
  
int getline(char s[], int lim)
{
    int c, i;
    
    i = 0;
    while(i < lim - 1) {
        c = getchar();
        if (c == '\n')
            break;
        else if (c == EOF)
            break;
        else
            s[i++] = c;
    }
    if (c == '\n') {
        s[i++] = c;
    }
    s[i] = '\0';
    return i;
}

