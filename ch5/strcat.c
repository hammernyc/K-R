#include <stdio.h>

char *stringcat(char *s, char *t);
int stringend(char *, char *);
void stringcpy(char*, char*, int); 

int main(int argc, char *argv[])
{
    char s[100] = "hello ";
    char *w = "world!";

    printf("%s\n", stringcat(s, w));

    printf("%d\n", stringend("hithere", "there"));
    printf("%d\n", stringend("hithere", "tere"));

    stringcpy(s, w, 3);
    printf("%s\n", s);
}

/* concatenate t to the end of s and return a pointer to s. (s must be big enough.)*/
char *stringcat(char *s, char *t)
{
    char *p = s;
    while (*s++);
    s -= 1; // step back to \0.
    while ((*s++ = *t++));
    return p;
}

int stringend(char *s, char *t)
{
    char *s2 = s;
    char *t2 = t;

    while (*s2++);
    while (*t2++);

    while (*--s2 == *--t2)
        if (t2 == t)
            return 1;

    return 0;
}

void stringcpy(char *s, char *t, int n)
{
    while ((*s++ = *t++) && --n)
        ;
    if (!n)
        *s = '\0';
}
