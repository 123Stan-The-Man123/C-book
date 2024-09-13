#include <stdio.h>
#include <math.h>

#define swap(t,x,y) { t temporary_value = x; \
    x = y; \
    y = temporary_value; }

int main(void) {
    int x = 3;
    int y = 2;

    printf("%lf\n", pow(x, y));
    swap(int,x,y);
    printf("%lf\n", pow(x, y));

    return 0;
}