#include <stdio.h>
#define MAXLINE 1000

void for_loop(char line[], int maxline);

int main(void) {
    char line[MAXLINE];

    for_loop(line, MAXLINE);
    printf("%s\n", line);
    return 0;
}

void for_loop(char s[], int lim) {
    int i, c;

    for (i = 0; i < lim-1; ++i) {
        if ((c = getchar()) == EOF) {
            break;
        }

        else if (c == '\n') {
            s[i] = c;
            ++i;
            break;
        }

        s[i] = c;
    }

    s[i] = '\0';
    return ;
}