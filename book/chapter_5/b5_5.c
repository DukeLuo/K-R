/* 5.5 字符指针与函数　*/

/* strcpy函数　*/
/* 版本一　*/
void strcpy(char *s, char *t)
{
    int i;

    i = 0;
    while ((s[i] = t[i]) != '\0')
        i++;
}

/* 版本二　*/
void strcpy(char *s, char *t)
{
    while ((*s++ = *t++) != '\0')
        ;
}

/* 版本三　*/
void strcpy(char *s, char *t)
{
    while (*s++ = *t++)
        ;
}

/* strcmp函数　*/
/* 版本一　*/
int strcmp(char *s, char *t)
{
    int i;

    for (i = 0; s[i] == t[i]; i++)
        if (s[i] == '\0')
            return 0;
    return s[i] - t[i];
}

/* 版本二　*/
int strcmp(char *s, char *t)
{
    for ( ; *s == *t; s++, t++)
        if (*s == '\0')
            return 0;
    return *s - *t;
}


