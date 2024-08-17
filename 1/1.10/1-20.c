#include <stdio.h>
#define MAXLINE 1000
#define TABSTOP 4

int my_getline(char line[], int maxline);

int main(void) {
    int len;
    char line[MAXLINE];

    while ((len = my_getline(line, MAXLINE)) > 0) {
        printf("%s", line);
    }

    return 0;
}

int my_getline(char s[], int lim) {
    int i, c, count, to_add;
    count = 0;

    for (i = 0; i < lim-1 && (c = getchar()) != EOF && c != '\n'; ++i) {
        if (c != '\t')  {
            s[i] = c;

            if (count == TABSTOP)
                count = 0;
        }

        else {
            to_add = TABSTOP - count;

            if (to_add == 0) {
                s[i] = c;
            }
            
            else {
                for(int j = 0; j < lim-1 && j < to_add; ++j) {
                    s[i + j] = ' ';
                }

                i += to_add - 1;
            }

            count = 0;
        }

        ++count;
    }

    if (c == '\n') {
        s[i] = c;
        ++i;
    }

    s[i] = '\0';
    return i;
}