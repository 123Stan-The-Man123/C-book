#include <stdio.h>

#define MAXLINE 1000

void my_strcat(char *s, char *t);

int main (void) {
    char s[MAXLINE] = "Join ";
    char t[MAXLINE] = "this";

    my_strcat(s, t);

    printf("s = %s\nt = %s\n", s, t);

    return 0;
}

void my_strcat(char *s, char *t) {
    while(*s++)
        ;
    
    s--;
    
    while (*s++ = *t++) 
        ;
    
    return ;
}