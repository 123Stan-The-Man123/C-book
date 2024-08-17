#include <stdio.h>
#define MAXLINE 1000
#define FOLD 32

int my_getline(char line[], int maxline);
void fold(char line[], int length, int fold);

int main(void) {
    int len;
    char line[MAXLINE];

    while ((len = my_getline(line, MAXLINE)) > 0) {
        fold(line, len, FOLD);
    }

    return 0;
}

int my_getline(char s[], int lim) {
    int c, i;
    i = 0;

    for (i; i < lim-1 && (c = getchar()) != EOF && c != '\n'; ++i) {
        s[i] = c;
    }

    if (c == '\n') {
        s[i] = c;
        ++i;
    }

    s[i] = '\0';
    return i;
}

void fold(char s[], int len, int fold) {
    int copy = fold;

    for (int i = 0; i < len; ++i) {
        if (i == fold) {
            printf("\n");
            printf("%c", s[i]);
            fold += copy;
        }
        
        else {
            printf("%c", s[i]);
        }
    }
}