#include <stdio.h>
#include <string.h>

#define MAXLINE 1000

void reverse(char s[], int len);

int main(void) {
    char s[MAXLINE] = "okay";

    reverse(s, strlen(s)-1);

    printf("%s\n", s);

    return 0;
}

void reverse(char s[], int len) {
    static int i;
    int temp;

    if (i < len) {
        temp = s[len];
        s[len] = s[i];
        s[i] = temp;
        i++;

        reverse(s, --len);
    }

    return ;
}