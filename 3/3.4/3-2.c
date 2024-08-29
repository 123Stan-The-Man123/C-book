#include <stdio.h>
#define MAXLINE 1000

void my_getline(char line[], int maxline);
void escape(char s[], char t[]);
void unescape(char s[], char t[]);

int main(void) {
    char line[MAXLINE], escaped[MAXLINE], unescaped[MAXLINE];

    my_getline(line, MAXLINE);
    escape(line, escaped);
    unescape(escaped, unescaped);
    
    return 0;
}

void my_getline(char s[], int lim) {
    int i, c;

    for (i = 0; i < lim-1 & (c = getchar()) != EOF && c != '\n'; ++i) {
        s[i] = c;
    }

    if (c == '\n') {
        s[i++] = c;
    }

    s[i] = '\0';
    return ;
}

void escape(char s[], char t[]) {
    int i, j;

    for (i = j = 0; s[i] != '\0'; ++i, ++j) {
        switch (s[i]) {
            case '\n':
                t[j++] = '\\';
                t[j] = 'n';
                break;
            
            case '\t':
                t[j++] = '\\';
                t[j] = 't';
                break;

            default:
                t[j] = s[i];
                break;
        }
    }

    t[j] = '\0';
    printf("Escaped: %s\n", t);
    return ;
}

void unescape(char s[], char t[]) {
    int i, j;

    for (i = j = 0; s[i] != '\0'; ++i, ++j) {
        switch (s[i]) {
        case '\\':
            switch(s[i+1]) {
                case 'n':
                    t[j] = '\n';
                    break;
                
                case 't':
                    t[j] = '\t';
                    break;
                
                default:
                    t[j++] = s[i];
                    t[j] = s[i+1];
                    break;
            }

            i++;
            break;

        default:
            t[j] = s[i];
        }
    }

    t[j] = '\0';
    printf("Unescaped: %s", t);
    return ;
}