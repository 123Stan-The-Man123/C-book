/* x &= (x-1) deletes the rightmost 1-bit in x because subtracting by 1 flips the 
bit in the mask, so the result of & will always be 0, deleting the bit. */

#include <stdio.h>

int bitcount(unsigned x);

int main(void) {
    int count = bitcount(1023);

    printf("Count: %d\n", count);

    return 0;
}

int bitcount(unsigned x) {
    int b;

    for (b = 0; x != 0; x &= (x - 1)) {
        b++;
    }

    return b;
}