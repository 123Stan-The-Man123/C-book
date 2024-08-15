#include <stdio.h>

void converter(void);

int main(void) {
    converter();

    return 0;
}

void converter(void) {
    float fahr, celcius;
    float lower, upper, step;

    lower = 0;
    upper = 300;
    step = 20;

    fahr = lower;
    while (fahr <= upper) {
        celcius = (5.0/9.0) * (fahr-32.0);
        printf("%3.0f %6.1f\n", fahr, celcius);

        fahr += step;
    }

    return ;
}