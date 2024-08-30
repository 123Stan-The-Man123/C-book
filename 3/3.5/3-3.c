#include <ctype.h>
#include <stdio.h>
#define MAXLINE 1000

void my_getline(char line[], int maxline);
void expand(char line[], char expanded[], int maxline);

int main(void) {
    char line[MAXLINE], expanded[MAXLINE];

    my_getline(line, MAXLINE);
    expand(line, expanded, MAXLINE);

    return 0;
}

void my_getline(char s[], int lim) {
    int i, c;

    for (i = 0; i < lim-1 && (c = getchar()) != EOF && c != '\n'; ++i) {
        s[i] = c;
    }

    if (c == '\n') {
        s[i++] = c;
    }

    s[i] = '\0';
    return ;
}

void expand(char s1[], char s2[], int lim) {
    int i, j, start, end;

    for (i = 0, j = 0; s1[i] != '\0' && i < lim-1; ++i, ++j) {
        if (s1[i] == '-' && i != 0 && isalnum(s1[i-1]) && isalnum(s1[i+1])) {
            --j;
            start = s1[i-1];
            end = s1[i+1];

            for (; start <= end; ++start, ++j) {
                s2[j] = start;
            }

            ++i, --j;
        }

        else {
            s2[j] = s1[i];
        }
    }

    s2[j] = '\0';

    printf("%s\n", s2);

    return ;
}