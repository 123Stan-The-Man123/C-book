#include <stdio.h>

#define MAXLINE 1000

void itoa(int num, char s[]);

int main(void) {
    char s[MAXLINE];

    itoa(-27356, s);

    printf("%s\n", s);

    return 0;
}

void itoa(int num, char s[]) {
    int digit;
    static int i;
    static int length;

    if (num < 0) {
        length++;
        s[i++] = '-';
        num = -num;
    }

    digit = num % 10;

    if ((num /= 10)) {
        length++;
        itoa(num, s);
    }
    
    s[i++] = digit + '0';

    if (i == length + 1)
        s[i] = '\0';

    return ;
}