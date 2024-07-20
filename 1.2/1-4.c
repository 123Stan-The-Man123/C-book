#include <stdio.h>

int main(void) {
    float celcius, fahr;
    float min, max, step;

    min = 0;
    max = 300;
    step = 20;

    celcius = min;
    printf("Celcius Fahr\n");

    while (celcius <= max) {
        fahr = (9.0/5.0) * celcius + 32;
        printf("%3.0f %6.0f\n", celcius, fahr);
        celcius += step;
    }
}