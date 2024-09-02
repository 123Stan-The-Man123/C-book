#include <stdio.h>
#include <string.h>

#define MAXLINE 1000

void itob(int n, char s[], int base);
void reverse(char s[]);

int main(void) {
    char line[MAXLINE];
    
    itob(128, line, 2);

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

void itob(int n, char s[], int b){
    int remainder, i;

    if (b <= 1 || b > 36) {
        strcpy(s, "Invalid base.");
        return ;
    }

    for (i = 0; n != 0; ++i) {
        s[i] = ((remainder = n % b) < 10) ? remainder + '0' : (remainder - 10) + 'A';

        n /= b;
    }

    s[i] = '\0';
    reverse(s);
}