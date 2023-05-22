/**
 * Exercise 2-4
*/

#include <stdio.h>
#include <string.h>

void squeeze(char *s, char *t);

char word[100];

int main() {
    strcpy(word, "hello");
    squeeze(word, "ho");
    printf("%s\n", word);
}

void squeeze(char *s, char *t) {
    int i, j;

    for (i = j = 0; s[i] != '\0'; i++) {
        if (strchr(t, s[i]) == NULL) {
            s[j++] = s[i];
        }
    }
    s[j] = '\0';
}
