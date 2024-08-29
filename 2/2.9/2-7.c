#include <stdio.h>

int invert_bits(int x, int p, int n);

int main(void) {
    int x = invert_bits(255, 1, 1);

    printf("%d\n", x);

    return 0;
}

int invert_bits(int x, int p, int n) {
    int reversed = ~(x >> (p+1-n) & ~(~0 << n));
    reversed = reversed << p;
    x = x & reversed;

    return x;
}