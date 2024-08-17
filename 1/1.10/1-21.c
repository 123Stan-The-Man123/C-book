#include <stdio.h>
#define MAXLINE 1000
#define TABSTOP 4


int my_getline(char line[], int maxline);
void entab(int maxline, int len, int tabstop, char altered[]);

int main(void) {
    int c, len;
    char line[MAXLINE];
    char altered[MAXLINE];

    while ((len = my_getline(line, MAXLINE)) > 0) {
        entab(MAXLINE, len, TABSTOP, altered);
        printf("%s", altered);
    }
}

int my_getline(char s[], int lim) {
    int i, c;
    
    for (i = 0; i < lim-1 && (c = getchar()) != EOF && c != '\n'; ++i) {
        s[i] = c;
    }

    if (c == '\n') {
        s[i] = c;
        ++i;
    }

    s[i] = '\0';
    return i;
}

void entab(int maxline, int len, int tabstop, char altered[]) {
    int spaces = len - 1;

    if (len <= 0) {
        return ;
    }

    int i = 0;

    while (spaces > 0) {
        if (spaces >= tabstop) {
            altered[i] = 't';
            spaces -= tabstop;
            ++i;
        }

        else {
            for (int j = 0; j < spaces; ++j) {
                altered[i] = 'b';
                ++i;
            }

            spaces = 0;
        }
    }

    altered[i] = '\n';
    ++i;
    altered[i] = '\0';
}