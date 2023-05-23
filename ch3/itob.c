#include <stdio.h>

#define BUFFER_MAX 128

void itob(int n, char s[], int b);
void reverse(char s[]);

int main(int argc, char *argv[])
{
    char s[BUFFER_MAX];
    itob(15,s,2);
    printf("itob(15, s, 2)=%s\n", s);
    itob(-31,s,16);
    printf("itob(-31, s, 16)=%s\n", s);


    return 0;
}

void itob(int n, char s[], int b)
{
    int i = 0;
    int sign = n;
    char digit;

    if (sign < 0)
        n = -n;

    do {
        digit = n % b;
        s[i++] = digit > 9 ? (digit - 10 + 'A') : (digit + '0');

    } while (n /= b);

    if (sign < 0)
        s[i++] = '-';
    s[i] = '\0';


    reverse(s);
}

void reverse(char s[])
{
    int i, j, t;

    for (j = 0; s[j] != '\0'; j++)
        ;
    for (i = 0,  j--; j > i; i++, j--) {
        t = s[j];
        s[j] = s[i];
        s[i] = t;
    }
}
