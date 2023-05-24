#include <stdio.h>
#include <stdlib.h> /* for atof() */
#include <ctype.h>
#include <math.h>

#define MAXOP 100 /* max size of operand or operator */
#define MAXVAL 100 /* maxium depth of the stack */
#define BUFSIZE 100 /* buffer for ungetch */
#define NUMBER 0 /* signal that a number was found */
#define POW 1 /* signal that POW was found */

int sp = 0; /* next free stack position */
int bufp = 0; /* next free position in buf */
double x = 0.0; /* most recently printed value */

char buf[BUFSIZE]; /* buffer for ungetch */
double val[MAXVAL]; /* value stack */


int getch(void);
void ungetch(int);
int getop(char[]);
void push(double);
double pop(void);

/* reverse Polish calculator */
int main (int argc, char *argv[])
{
    int type;
    double op2;
    char s[MAXOP];

    while ((type = getop(s)) != EOF) {
        switch (type) {
            case NUMBER:
                push(atof(s));
                break;
            case POW: // this doesn't quite work...
                op2 = pop();
                push(pow(pop(), op2));
                break;
            case '+':
                push(pop() + pop());
                break;
            case '-':
                op2 = pop();
                push(pop() - op2);
                break;
            case '*':
                push(pop() * pop());
                break;
            case '/':
                op2 = pop();
                if (op2 != 0.0)
                    push(pop() / op2);
                else
                    printf("error: zero divisor\n");
                break;
            case '%':
                op2 = pop();
                if (op2 != 0.0)
                    push((int) pop() % (int) op2);
                else
                    printf("error: zero divisor\n");
                break;
            case '\n':
                x = pop();
                printf("\t%.8g\n", x);
                break;
            case 'x':
                push(x);
                break;
            default:
                printf("error: unknown command %s\n", s);
                break;
        }
    }
    return 0;
}

/* getop: get next operator or numeric operand */
int getop(char s[])
{
    int i, c;

    while ((s[0] = c = getch()) == ' ' || c == '\t')
        ;
    s[1] = '\0';

    if (c == 'p') {
        if ((s[++i] = c = getch()) == 'o') {
            if ((s[++i] = c = getch()) == 'w') {
                return POW;
            }
            ungetch(c);
        }
        ungetch(c);
        return c;
    }

    if (!isdigit(c) && c != '.' && c != '-')
        return c; /* NaN*/
    i = 0;
    if (c == '-') {
        if (!isdigit(s[++i] = c = getch())) {
            ungetch(c);
            return '-';
        }
    }
    if (isdigit(c)) /* collect integer part */
        while (isdigit(s[++i] = c = getch()))
            ;
    if (c == '.') /* collect fraction part */
        while (isdigit(s[++i] = c = getch()))
            ;
    s[i] = '\0';
    if (c != EOF)
        ungetch(c);
    return NUMBER;
}

/* push: push f onto value stack */
void push(double f) 
{
    if (sp < MAXVAL) 
        val[sp++] = f;
    else   
        printf("error: stack full, can't push %g\n", f);
}

/* pop: pop and return top value from stack */
double pop(void)
{
    if (sp > 0)
        return val[--sp];
    else 
        printf("error: stack empty\n");
    return 0.0;
}

/* get a (possibly pushed back) char */
int getch(void)
{
    return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c)
{
    if (bufp >= BUFSIZE)
        printf("ungetch: too many characters\n");
    else  
        buf[bufp++] = c;
}
