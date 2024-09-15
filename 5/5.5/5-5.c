#include <stdio.h>

#define MAXLINE 1000

char *my_strncpy(char *s, char *t, size_t n);
char *my_strncat(char *s, char *t, size_t n);
int my_strncmp(char *s, char *t, size_t n);

int main(void) {
    char s[MAXLINE];
    char t[MAXLINE] = "Hello, this string will be copied to s in part";

    printf("strncpy:\ns = %s\n", my_strncpy(s, t, 5));
    printf("strncat:\ns = %s\n", my_strncat(s, t, 15));
    printf("strncmp:\n%d\n", my_strncmp(s, t, 15));

}

char *my_strncpy(char *s, char *t, size_t n) {
    char *s_start = s;

    for (; s < s_start + n && *t != '\0'; (*s++ = *t++))
        ;
    
    *s = '\0';

    return s_start;
}

char *my_strncat(char *s, char *t, size_t n) {
    char *s_start = s;
    char *s_new;

    while (*s++)
        ;

    s_new = --s;
    
    while((*s++ = *t++) && s < (s_new + n))
        ;
    
    *s = '\0';
    
    return s_start;

}

int my_strncmp(char *s, char *t, size_t n) {
    char *s_start = s;

    while (*s++ == *t++ && s < s_start + n)
        ;
    
    return *--s - *--t;
    
}