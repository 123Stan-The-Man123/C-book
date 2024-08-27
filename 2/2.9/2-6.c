#include <stdio.h>

unsigned int set_bits(unsigned x, int p, int n, int y);

int main(void) {
    unsigned int result =  set_bits(255, 4, 3, 8);

    printf("%d\n", result);

    return 0;
}

unsigned int set_bits(unsigned x, int p, int n, int y) {
    return (x & ~((~(~0 << n)) << (p - n)) | (y & ~(~0 << n)) << (p-n));
}