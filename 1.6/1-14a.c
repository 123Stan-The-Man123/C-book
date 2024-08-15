#include <stdio.h>

#define SIZE 93

int main(void) {
    int c, largest, limit;
    int characters[SIZE];

    for (int i = 0; i < SIZE; ++i) {
        characters[i] = 0;
    }

    while ((c = getchar()) != EOF) {
        if (c >= '!' && c <= '~') {
            ++characters[c - '!'];
        }
    }

    for (int i = 0; i < SIZE; ++i) {
        if (characters[i] > largest) {
            largest = characters[i];
        }
    }

    limit = largest;

    for (int i = 0; i < limit; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            if (characters[j] == 0)
                ;

            else if (characters[j] < largest) {
                printf("  ");
            }

            else {
                printf("* ");
            }
        }

        --largest;
        printf("\n");
    }

    for (int j = 0; j < SIZE; ++j) {
        if (characters[j] != 0) {
            printf("%c ", j + '!');
        }
    }

    return 0;
}