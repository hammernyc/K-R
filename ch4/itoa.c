#include <stdio.h>
int itoa(int n, char str[], int i);
int main(int argc, char *argv[])
{
    char str[100];
    itoa(-120, str, 0);
    printf("%s\n", str);
    return 0;
}

int itoa(int n, char str[], int i) {
    if (n < 0) {
        str[i++] = '-';
        n = -n;
    }
    if (n / 10) {
        i = itoa(n/10, str, i++);
    }
    str[i++] = n % 10 + '0';
    str[i] = '\0';
    return i;
}
