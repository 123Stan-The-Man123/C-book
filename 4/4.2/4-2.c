#include <ctype.h>
#include <math.h>
#include <stdio.h>

#define MAXLINE 100

int my_getline(char line[], int maxline);
double atof(char s[]);

/* rudimentary calculator */
int main(void) {
    double sum;
    char line[MAXLINE];
    sum = 0;
    
    while (my_getline(line, MAXLINE) > 0)
        printf("\t%g\n", sum += atof(line));
    
    return 0;
}

int my_getline(char s[], int lim) {
    int i, c;
    i = 0;

    while (--lim > 0 && (c = getchar()) != EOF && c != '\n') {
        s[i++] = c;
    }

    if (c == '\n') {
        s[i++] = c;
    }

    s[i] = '\0';
    return i;
}

/* atof:  convert string s to double */
double atof(char s[]) {
    double val, power, num;
    int i, sign;
    
    for (i = 0; isspace(s[i]); i++)  /* skip white space */
        ;
    
    sign = (s[i] == '-') ? -1 : 1;

    if (s[i] == '+' || s[i] == '-')
        i++;
    
    for (val = 0.0; isdigit(s[i]); i++)
        val = 10.0 * val + (s[i] - '0');
    
    if (s[i] == '.')
        i++;
    
    for (power = 1.0; isdigit(s[i]); i++) {
        val = 10.0 * val + (s[i] - '0');
        power *= 10;
    }
    
    num = sign * val / power;

    if (s[i] == 'e' || s[i] == 'E') {
        i++;

        if (!(isdigit(s[i])) && (s[i] != '-' && s[i] != '+')) {
            return 0;
        }

        sign = (s[i] == '-') ? -1 : 1;

        if (s[i] == '+' || s[i] == '-')
            i++;

        for (val = 0.0; isdigit(s[i]); i++)
            val = 10.0 * val + (s[i] - '0');

        power = pow(10, val*sign);

        num *= power;
    }

    return num;
}