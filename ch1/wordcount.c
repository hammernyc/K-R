#include <stdio.h>

#define IN  1
#define OUT 0

int main()
{
    int c, nl, nw, nc, state;
    nl = 1;
    nw = nc = 0;

    state = OUT;

    while ((c = getchar()) != EOF) {
        ++nc;
        if (c == '\n')
            ++nl;
        if (c == ' ' || c == '\n' || c == '\t')
            state = OUT;
        else if (state == OUT) {
            state = IN;
            ++nw;
        }
    }
    printf("\nlines: %d, words: %d, characters: %d\n", nl, nw, nc);
    return 0;
}