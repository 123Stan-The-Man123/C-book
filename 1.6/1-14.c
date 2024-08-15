#include <stdio.h>

#define SIZE 93

int main(void) {
    int c, count;
    int characters[SIZE];

    count = 0;

    for (int i = 0; i < SIZE; ++i) {
        characters[i] = 0;
    }

    while ((c = getchar()) != EOF) {
        if (c >= '!' && c <= '~') {
            ++characters[c - '!'];
            ++count;
        }
    }

    if (!count) {
        return -1;
    }

    for (int i = 0; i < SIZE; ++i) {
        if (characters[i] != 0) {
            printf("%c: ", i + '!');

            for (int j = 0; j < characters[i]; ++j) {
                printf("*");
            }

            printf("\n");
        }
    }
    return 0;
}