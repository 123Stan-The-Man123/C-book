#include <ctype.h>
#include <stdio.h>

#define SIZE 10

int buf[SIZE];
int bufp = 0;

int getch(void);
void ungetch(int c);

int main(void) {
    int n, getfloat(float *);
    float array[SIZE];

    for (n = 0; n < SIZE && getfloat(&array[n]) != EOF; n++) {
        ;
    }

    return 0;
}

int getch(void) {
    return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c) {
    if (bufp >= SIZE)
        printf("error: too many characters\n");
    
    else
        buf[bufp++] = c;
}

int getfloat(float *pn) {
    int c, sign, temp;
    float position;

    while (isspace(c = getch()))
        ;
    
    if (!isdigit(c) && c != EOF && c != '+' && c != '-' && c != '.') {
        ungetch(c);
        return 0;
    }

    sign = (c == '-') ? -1 : 1;

    if (c == '+' || c == '-') {
        temp  = c;
        c = getch();

        if (!isdigit(c)) {
            ungetch(c);
            ungetch(temp);
            return 0;
        }
    }
    
    for (*pn = 0; isdigit(c); c = getch())
        *pn = 10 * *pn + (c - '0');
    
    if (c == '.') {
        for (c = getch(), position = 1.0; isdigit(c); c = getch(), position *= 10) {
            *pn += (c - '0') / (10.0 * position);
        }
    }
    
    *pn *= sign;

    if (c != EOF)
        ungetch(c);
    
    return c;
}