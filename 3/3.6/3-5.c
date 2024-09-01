#include <stdio.h>
#include <string.h>

#define MAXLINE 1000

void itoa(int n, char s[], int base);
void reverse(char s[]);

int main(void) {
    char line[MAXLINE];
    
    itoa(4308760, line, 2);

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

void itoa(int n, char s[], int b){
    int remainder, i;

    if (b <= 0 || b > 36) {
        strcpy(s, "Invalid base.");
        return ;
    }

    for (i = 0; n != 0; ++i) {
        if ((remainder = n % b) < 10)
            s[i] = remainder + '0';
        
        else 
            s[i] = (remainder - 10) + 'A'; 
        
        n /= b;
    }

    s[i] = '\0';
    reverse(s);
}