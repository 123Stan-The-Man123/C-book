#include <stdio.h>
#define MAXLINE 1000
#define TRAILING 1
#define IGNORE 0

int my_getline(char line[], int maxline);
int remove_trailing(char line[], int len);

int main(void) {
    int len;
    char line[MAXLINE];

    while ((len = my_getline(line, MAXLINE)) > 0) {
        len = remove_trailing(line, len);

        if (len == 0 && line[0] == '\n')
            line[0] = '\0';
        
        printf("%s", line);
    }

    return 0;
}

int my_getline(char s[], int lim) {
    int c, i;

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

int remove_trailing(char line[], int len) {
    int newline = 0;

    if (line[--len] == '\n') {
        line[len] = '\0';
        newline = 1;
    }

    while (--len > 0 && (line[len] == ' ' || line[len] == '\t')) {
        line[len] = '\0';
    }

    ++len;

    if (newline)
        line[len] = '\n';
    
    return ++len;
}
