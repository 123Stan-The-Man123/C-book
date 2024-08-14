#include <stdio.h>

int main(void) {
    int c, blank, tab, nl = 0;
    while ((c = getchar()) != EOF) {
        if (c == ' ') {
            ++blank;
        }
        else if (c == '\t') {
            ++tab;
        }
        else if (c == '\n') {
            ++nl;
        }
        else
            ;
    }

    printf("\nBlanks: %d\nTabs: %d\nNewlines: %d", blank, tab, nl);
    return 0;
}