#include <stdio.h>
#include <string.h>

#define MAXLINE 1000

int strindex(char s[], char t[]);

char pattern[] = "ould"; /* pattern to search */
char str[] = "whoulda, shoulda, coulda";

int main(int argc, char *argv[])
{
    printf("rightmost index of \"%s\" in \"%s\": %d\n", pattern, str, strindex(str, pattern));
}

/* strindex: return rightmost index of t in s, -1 if none */
int strindex(char s[], char t[])
{
    int i, j, tlen;
    tlen = strlen(t);

    for (i = strlen(s) - tlen; i >= 0; i--) {
        for (j = 0; j < tlen; j++) {
            if (s[i + j] != t[j])
                break;
            if (j == tlen - 1)
                return i;
        }
    }
    return -1;
}
