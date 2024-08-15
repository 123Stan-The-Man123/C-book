#include <stdio.h>

#define OUT 1
#define IN 0
#define SIZE 5

int main(void) {
    int c, boolean, word_length, current, longest, limit;
    word_length = current = longest = 0;
    int lengths[SIZE];

    for (int i = 0; i < SIZE; ++i) {
        lengths[i] = 0;
    }

    while ((c = getchar()) != EOF) {
        if ((c == ' ' || c == '\n' || c == '\t') && boolean) 
            ;

        else if (c == ' ' || c == '\n' || c == '\t') {
            boolean = IN;
            lengths[current] = word_length;
            ++current;

            if (word_length > longest)
                longest = word_length;
            
            word_length = 0;
        }
        
        else if (boolean) {
            boolean = IN;
            ++word_length;
        }

        else
            ++word_length;
    }

    limit = longest;

    for (int i = 0; i < limit; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            if (lengths[j] < longest)
                printf("     ");
            
            else
                printf("*    ");
        }

        --longest;
        printf("\n");
    }

    return 0;
}