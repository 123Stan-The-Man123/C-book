#include <stdio.h>

#define END 1
#define WORD 0
#define SIZE 5

int main(void) {
    int c, i, j, current, boolean, word_length;
    int lengths[SIZE];
    word_length = current = 0;

    for (i = 0; i < SIZE; ++i) {
        lengths[i] = 0;
    }

    while ((c = getchar()) != EOF) {
        if ((c == ' ' || c == '\n' || c == '\t') && boolean) 
            ;
        
        else if (c == ' ' || c == '\n' || c == '\t') {
            lengths[current] = word_length;
            ++current;
            word_length = 0;
            boolean = END;
        }

        else if (boolean) {
            boolean = WORD;
            ++word_length;
        }
        
        else
            ++word_length;
    }

    for (i = 0; i < SIZE; ++i) {
        j = lengths[i];

        while (j >= 0) {
            printf("--");
            --j;
        }
        printf("|\n");

        j = lengths[i];
        
        while (j >= 0) {
            printf("  ");
            --j;
        }
        printf("|\n");

        j = lengths[i];

        while (j >= 0) {
            printf("--");
            --j;
        }
        printf("|\n\n");
    }

    return 0;
}