#include <stdio.h>
#define MAXLINE 1000

int my_getline(char line[], int maxline);
void remove_comments(char line[], int len);

int main(void) {
    int len;
    char line[MAXLINE];

    while ((len = my_getline(line, MAXLINE)) > 0) {
        remove_comments(line, len);
    }

    return 0;
}

int my_getline(char s[], int lim) {
    int c, i;
    
    for (i = 0; i < lim-1 && (c = getchar()) != EOF; ++i) {
        s[i] = c;
    }

    if (c == '\n') {
        s[i] = '\n';
        ++i;
    }

    s[i] = '\0';
    return i;
}

void remove_comments(char s[], int len) {
    int i;
    
    for (i = 0; i < len; ++i) {
        if (s[i] == '/' && s[i+1] == '*') {
            i += 2;
        
            while (!(s[i] == '*' && s[i+1] == '/')) {
                ++i;
            }

            ++i;
        }

        else {
            printf("%c", s[i]);
        }
    }

    printf("\n");
    return ;
}