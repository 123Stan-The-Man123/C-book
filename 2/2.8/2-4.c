#include <stdio.h>
#define MAXLINE 1000

int my_getline(char line[], int maxline);
void squeeze(char line1[], int lim1, char line2[], int lim2, char squeezed[]);

int main(void) {
    char line1[MAXLINE], line2[MAXLINE], squeezed[MAXLINE];

    int lim1 = my_getline(line1, MAXLINE);
    int lim2 = my_getline(line2, MAXLINE);
    squeeze(line1, lim1, line2, lim2, squeezed);

    printf("%s", squeezed);

    return 0;
}

int my_getline(char s[], int lim) {
    int i, c;

    for (i = 0; i < lim-1 && (c = getchar()) != EOF && c != '\n'; ++i) {
        s[i] = c;
    }

    if (c == '\n') {
        s[i++] = c;
    }

    s[i] = '\0';
    return i;
}

void squeeze(char s1[], int lim1, char s2[], int lim2, char result[]) {
    int i, j;
    int position = 0;
    int remove = 0;

    for (i = 0; i < lim1-1; ++i) {
        for (j = 0; j < lim2-1; j++) {
            if (s1[i] == s2[j]) {
                remove = 1;
            }
        }

        if (remove) {
            remove = 0;
        }

        else {
            result[position++] = s1[i];
        }
    }

    result[position++] = '\n';
    result[position] = '\0';
    return ;
}