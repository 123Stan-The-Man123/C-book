#include <stdio.h>

int main(void) {
    int c;
    while ((c = getchar()) != EOF) {
        if (c == ' ' || c == '\t' || c == '\n')
            printf("\n");
        
        else
            putchar(c);
    }

    return 0;
}