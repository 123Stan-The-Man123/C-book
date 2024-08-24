#include <ctype.h>
#include <math.h>
#include <stdio.h>
#define MAXLINE 1000

int my_getline(char line[], int maxline);
void htoi(char line[], int len);

int main(void) {
    int len;
    char line[MAXLINE];

    len = my_getline(line, MAXLINE);
    htoi(line, len);

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

void htoi(char s[], int len) {
    int i = 0;
    long multiplier = pow(16, len);
    int hex = 0;
    char current;

    if (s[i] == '0' && s[i+1] == 'x' || s[i+1] == 'X') {
        i = 2;
        multiplier = multiplier / (16*16);
    }

    if (s[len] == '\0') {
        multiplier /= 16;
    }

    if (s[len-1] == '\n') {
        multiplier /= 16;
    }

    for (i; i < len-1; ++i) {
        current = s[i];

        if (current >= '0' && current <= '9') {
            hex += (current - '0') * multiplier;
        }

        else if (current >= 'A' && current <= 'F') {
            hex += (current - 'A' + 10) * multiplier;
        }

        else if (current >= 'a' && current <= 'f') {
            hex += (current - 'a' + 10) * multiplier;
        }

        else {
            printf("Invalid input.\n");
            return ;
        }

        multiplier /= 16;
    }

    printf("%d", hex);
    return ;
}