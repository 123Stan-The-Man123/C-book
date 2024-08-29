#include <stdio.h>
#define INT 32

int rightrot(int x, int n);

int main(void) {
    int x = rightrot(256, 7);

    printf("%d\n", x);
    
    return 0;
}

int rightrot(int x, int n) {
    return ((x >> n) | (x << (INT - n)));
}