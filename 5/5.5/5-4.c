#include <stdio.h>

#define MAXLINE 1000

int strend (char *s, char *t);

int main (void) {
    char s[MAXLINE] = "This is cool!";
    char t[MAXLINE] = "cool!";

    (strend(s, t)) ? printf("s ends with t\n") : printf("s doesn't end with t\n");

    return 0;
}

int strend(char *s, char *t) {
    char *t_start = t;

    while (*s++)
        ;
    
    while (*t++)
        ;
    
    s--, t--;

    while (t != t_start) {
        if (*s-- == *t--)
            ;
        
        else
            return 0;
    }

    return 1;
}