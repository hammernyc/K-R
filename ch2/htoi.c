#include <stdio.h>
#include <string.h>

int htoi(char s[]);

int ishexdigit(char c);
int hexdigittoi(char c);


int main(int argc, char *argv[])
{
    printf("\"0\" to int = %d\n", htoi("0"));
    printf("\"1A\" to int = %d\n", htoi("1A"));
    printf("\"1C0\" to int = %d\n", htoi("1C0"));
    printf("\"FfFf\" to int = %d\n", htoi("FfFf"));

    return 0;
}

int htoi(char s[]) {
    int i;
    int n = 0;
    int col = 1;

    for (i = strlen(s) - 1; i >= 0; i--) {
        n += col * hexdigittoi(s[i]);
        col *= 16;
    }
    return n;
}

int ishexdigit(char c) {
    if ((c >= '0' && c <= '9') || 
        (c >= 'A' && c <= 'F') ||
        (c >= 'a' && c <= 'f')) {
            return 1;
        }
    return 0;
}

int hexdigittoi(char c) {
    if ('0' <= c && c <= '9')  {
        return c - '0';
    }
    if ('a' <= c && c <= 'f') {
        return 10 + c - 'a';
    }
    if ('A' <= c && c <= 'F') {
        return 10 + c - 'A';
    }
    return 0;
}
