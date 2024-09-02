#include <stdio.h>

#define MAXLINE 1000

void itoa(int n, char s[], int w);
void reverse(char s[]);

int main(void) {
    char line[MAXLINE];
    
    itoa(-2147483648, line, 15);

    printf("%s\n", line);

    return 0;
}

void reverse(char s[]) {
    int i, j;
    char temp;

    for (i = 0; s[i] != '\0'; ++i) {
        ;
    }

    --i;

    for (j = 0; i >= j; ++j, --i) {
        temp = s[i];
        s[i] = s[j];
        s[j] = temp;
    }

    return ;
}

void itoa(int n, char s[], int w){
    int i, sign;
    
    sign = n;
    
    i = 0;

    if (sign < 0) {
        do { 
            s[i++] = (-(n % 10)) + '0';  
        } while ((n /= 10) <= -1);

        s[i++] = '-';
    }

    else {
        do { 
            s[i++] = n % 10 + '0';  
        } while ((n /= 10) > 0); 
    }

    while (i < w) {
        s[i++] = ' ';
    }

    s[i] = '\0';
    reverse(s);
}