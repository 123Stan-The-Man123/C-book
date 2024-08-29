#include <stdio.h>
#define MAXLINE 1000

int my_getline(char line[], int maxline);
void lower(char line[], char lower[]);


int main(void) {
    char line[MAXLINE], lower_line[MAXLINE];
    int length = my_getline(line, MAXLINE);
    lower(line, lower_line);

    printf("Original: %sLower: %s", line, lower_line);
    
    return 0;
}

int my_getline(char s[], int lim) {
    int c, i;

    for (i = 0; i < lim-1 && (c = getchar()) != EOF && c != '\n'; ++i) {
        s[i] = c;
    }

    if (c == '\n') {
        s[i++] = c;
    }

    s[i] = '\0';
    return i;
}

void lower(char s[], char lower[]) {
    int i;


    for (i = 0; s[i] != '\0'; ++i) {
        lower[i] = (s[i] >= 'a' && s[i] <= 'z' || (s[i] < 'A' || s[i] > 'Z')) ? s[i] : s[i] + 32;
    }

    lower[i] = '\0';
    return ;
}