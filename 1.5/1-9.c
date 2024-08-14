#include <stdio.h>

int main(void) {
    int c, boolean;

    while ((c = getchar()) != EOF) {
        if (c == ' ' && boolean == 1)
            ;

        else if (c == ' ') {
            putchar(c);
            boolean = 1;
        }

        else {
            putchar(c);
            boolean = 0;
        }
    }

    return 0;
}