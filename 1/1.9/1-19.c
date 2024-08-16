#include <stdio.h>
#define MAXLINE 1000

int my_getline(char line[], int maxline);
void reversed(char line[], int len);

int main(void) {
    int len;
    char line[MAXLINE];

    while ((len = my_getline(line, MAXLINE)) > 0) {
        reversed(line, len - 1);
    }

    return 0;
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

void reversed(char s[], int len) {
    int i = 0;
    char result[MAXLINE];

    for (len; len >= 0; --len) {
        result[i] = s[len];
        ++i;
    }

    result[i] = '\n';
    ++i;
    result[i] = '\0';

    printf("%s", result);
}