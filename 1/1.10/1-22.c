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
    int start_line = 0;
    int safe = -1; // Last safe break point (space/tab)
    int no_blanks = 1; // Flag to indicate if no spaces/tabs are found

    for (int i = 0; i < len; ++i) {
        if (s[i] == ' ' || s[i] == '\t') {
            safe = i; // Update safe break point
            no_blanks = 0; // Found at least one space/tab
        }

        // If the current line length exceeds the fold length
        if ((i - start_line) >= fold) {
            if (safe >= start_line) {
                // Break at the last safe point if available
                for (int k = start_line; k < safe; ++k) {
                    printf("%c", s[k]);
                }
                printf("\n");
                start_line = safe + 1; // Move start_line to the next character after safe
            } else {
                // If no space/tab was found, force break at fold limit
                for (int k = start_line; k <= i; ++k) {
                    printf("%c", s[k]);
                }
                printf("\n");
                start_line = i + 1; // Move start_line to the next character after fold
            }
            safe = -1; // Reset safe point
            no_blanks = 1; // Reset no_blanks flag
        }
    }

    // Print remaining characters after the last fold
    for (int k = start_line; k < len; ++k) {
        printf("%c", s[k]);
    }
}