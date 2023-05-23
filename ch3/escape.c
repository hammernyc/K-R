#include <stdio.h>

void escape(char *s, char *t);
void unescape(char *s, char *t);

int main(void)
{
    char s[51];
    char t[50] = "Hello,\n\tWorld\\world!\"\n";
    

    escape(s, t);
    printf("Escaped string:\n%s\n", s);

    unescape(s, t);
    printf("Original string:\n%s\n", s);

    return 0;
}

/* copies t into s, escaping special characters */
void escape(char *s, char *t)
{
    int i = 0;
    int j = 0;
    int c;

    while ((c = t[i]) != '\0') {
        switch (c) {
            case '\n':
                s[j++] = '\\';
                s[j] = 'n';
                break;
            case '\t':
                s[j++] = '\\';
                s[j] = 't';
                break;
            case '\\':
                s[j++] = '\\';
                s[j] = '\\';
                break;
            case '\"':
                s[j++] = '\\';
                s[j] = '\"';
                break;
            default:
                s[j] = t[i];
                break;
        }
        i++;
        j++;
    }
    s[j] = '\0';
}

/* copies t into s, un-escaping special characters */
void unescape(char *s, char *t)
{
    int i = 0;
    int j = 0;


    while (t[i] != '\0') {
        switch (t[i]) {
            case '\\':
                switch (t[++i]) {
                    case 'n':
                        s[j] = '\n';
                        break;
                    case 't':
                        s[j] = '\t';
                        break;
                    case '\\':
                        s[j] = '\\';
                        break;
                    case '\"':
                        s[j] = '\"';
                        break;
                    default: // not an escape sequence
                        s[j++] = '\\';
                        s[j] = t[i];
                        break;
                }
            default:
                s[j] = t[i];
                break;
        }
        i++;
        j++;
    }
    s[j] = '\0';
}
