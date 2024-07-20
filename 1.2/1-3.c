#include <stdio.h>

/* printf Fahrenheit-Celcius table
    for fahr = 0, 20, ..., 300; floating point */

int main(void) {
    float fahr, celcius;
    float lower, upper, step;

    lower = 0;      // Lower limit of tomperature scale
    upper = 300;    // Upper limit
    step = 20;      // Step size

    fahr = lower;
    printf("Fahr  Celcius\n");

    while (fahr <= upper) {
        celcius = (5.0/9.0) * (fahr-32.0);
        printf("%3.0f %6.1f\n", fahr, celcius);

        fahr += step;
    }
}