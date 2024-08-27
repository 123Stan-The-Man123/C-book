#include <stdio.h>
#define MAXLINE 1000

int my_getline(char line[], int maxline);
int get_location(char line1[], int len1, char line2[], int len2);

int main(void) {
    char line1[MAXLINE], line2[MAXLINE];
    int len1, len2, location;

    len1 = my_getline(line1, MAXLINE);
    len2 = my_getline(line2, MAXLINE);

    location = get_location(line1, len1, line2, len2);

    printf("%d\n", location);

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

int get_location(char s1[], int lim1, char s2[], int lim2) {
    int i, j, location, found;
    location = -1;
    found = 0;

    for (i = 0; i < lim1-1; ++i) {
        for (j = 0; j < lim2-1; ++j) {
            if (s1[i] == s2[j]) {
                location = i;
                found = 1;
                break;
            }
        }

        if (found) {
            break;
        }
    }

    return ++location;
}