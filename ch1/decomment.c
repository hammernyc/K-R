#include <stdio.h>

#define MAXLINE 1000
#define OUT 0
#define IN_STANDARD_COMMENT 1
#define IN_TRAILING_COMMENT 2
#define IN_STRING 3

char line[MAXLINE];

void decomment(void);


int main()
{
    extern char line[MAXLINE];
    int i, c;

    for (i = 0; (c = getchar()) != EOF; ++i)
        line[i] = c;
    line[i] = '\0';

    decomment();
    printf("%s", line);

    return 0;
}

void decomment()
{
    extern char line[MAXLINE];
    int state, i, c;
    state = OUT;

    for (i = 0; (c = line[i]) != '\0'; ++i) {

        if (state == OUT && c == '\"') {
            state = IN_STRING;
        } else if (state == IN_STRING & c == '\"') {
            state = OUT;
        } else if (state == OUT &&
                   line[i] == '/' &&
                   line[i+1] == '/') {
            state = IN_TRAILING_COMMENT;
            line[i] = ' ';
            line[i+1] = ' ';
        } else if (state == OUT &&
                   line[i] == '/' &&
                   line[i+1] == '*') {
            state = IN_STANDARD_COMMENT;
            line[i] = ' ';
            line[i+1] = ' ';
        } else if (state == IN_TRAILING_COMMENT && c == '\n') {
            state = OUT;
        } else if (state == IN_STANDARD_COMMENT &&
                   line[i] == '*' &&
                   line[i+1] == '/') {
            line[i] = ' ';
            line[i+1] = ' ';
            state = OUT;
         }

        if (state == IN_TRAILING_COMMENT || state == IN_STANDARD_COMMENT) {
            line[i] = ' ';
        }
    }
}
