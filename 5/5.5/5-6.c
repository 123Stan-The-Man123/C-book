#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

#define MAXLINE 1000
#define BUFSIZE 100

char buf[BUFSIZE];
static int bufp = 0;

char *my_getline(char *s, size_t maxline);
int my_atoi(char *s);
void reverse(char *s);
char *my_itoa(char *s, int n);
int my_htoi(char *s, size_t len);
char *my_itob(char *s, size_t n, size_t b);
int str_index(char *s, char *t);
int getch(void);
void ungetch(int c);
int getop(char *s);

int main(void) {
    char s[MAXLINE];
    char digit[MAXLINE] = "-2435452";
    int num = -256;
    char hexadecimal[MAXLINE] = "0xFFFFFF";
    char returned_hex[MAXLINE];
    size_t base = 2;
    char string[MAXLINE] = "This is a string!";
    char substring[MAXLINE] = "ring!";
    char output[MAXLINE];

    printf("You entered: %s", my_getline(s, MAXLINE));
    printf("The string \"%s\" is now integer: %d\n", digit, my_atoi(digit));
    printf("The int %d is now the string: \"%s\"\n", num, my_itoa(s, num));
    printf("The hexadecimal \"%s\" is the integer: %d\n", hexadecimal, my_htoi(hexadecimal, 8));
    printf("The integer %d in the base %zd is: %s\n", 255, base, my_itob(returned_hex, 255, base));
    printf("The sub-string \"%s\" is in the string \"%s\" at location: %d\n", substring, string, str_index(string, substring));
    getop(output);
    printf("Getop: %s\n", output);

    return 0;
}

char *my_getline(char *s, size_t lim) {
    char *s_start = s;

    while((*s++ = getchar()) != '\n' && (s - s_start) < lim - 1)
        ;
    
    *s = '\0';

    return s_start;
}

int my_atoi(char *s) {
    int num = 0; 
    int digit;
    int sign = 1;

    if (*s == '-') {
        sign = -sign;
        *s++;
    }

    while(*s != '\0' && isdigit(digit = *s++)) {
        num += (digit - '0');
        num *= 10;
    }

    return (num /= 10) * sign;
}

void reverse(char *s) {
    char *s_start = s;
    char temp;
    int len = 0;

    while (*s++)
        len++;
    
    s -= 2;

    while (s > s_start) {
        temp = *s;
        *s = *s_start;
        *s_start = temp;
        s--, s_start++;
    }
    

    return ;
}

char *my_itoa(char *s, int n) {
    char *s_start = s;
    int sign = 1;

    if (n < 0) {
        n = -n;
        sign = -sign;
    }

    while (n) {
        *s++ = (n % 10) + '0';
        n /= 10;
    }

    if (sign < 0)
        *s++ = '-';

    *s = '\0';

    reverse(s_start);

    return s_start;
}

int my_htoi(char *s, size_t len) {
    int num = 0;
    long multiplier;

    if (*s == '0' && (*(s+1) == 'x' || *(s+1) == 'X')) {
        s += 2;
        len -= 2;
    }

    multiplier = pow(16, len-1);

    while (multiplier) {
        if (*s >= '0' && *s <= '9')
            num += (*s - '0') * multiplier;
        
        else if (*s >= 'A' && *s <= 'F')
            num += (*s - 'A'+ 10) * multiplier;
        
        else if (*s >= 'a' && *s <= 'f')
            num += (*s - 'a' + 10) * multiplier;
        
        else {
            printf("%d\n", num);
            printf("Invalid hex\n");
            return 0;
        }

        s++;
        multiplier /= 16;
    }

    return num;
}

char *my_itob(char *s, size_t n, size_t b) {
    int remainder;
    char *s_start = s;

    if (b < 2 || b > 36) {
        strcpy(s, "Invalid base\n");
        return s;
    }

    while (n) {
        *s++ = ((remainder = n % b) < 10) ? remainder + '0' : (remainder - 10) + 'A';
        n /= b;
    }

    *s = '\0';

    reverse(s_start);

    return s_start;
}

int str_index(char *s, char *t) {
    char *s_start = s;
    char *t_start = t;
    char *j;

    for (; *s != '\0'; s++) {
        for (j = s, t = t_start; *t != '\0' && *j == *t; j++, t++)
            ;
        
        if (t > t_start && *t == '\0') {
            return s - s_start;
        }
    }

    return -1;
}

int getch(void) {
    return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c) {
    if (bufp >= BUFSIZE)
        printf("ungetch: too manu characters\n");

    else
        buf[bufp++] = c;
}

int getop(char *s) {
    int c;

    while (isspace(*s = c = getch()))
        ;
    
    *(s+1) = '\0';

    if (!isdigit(c) && c != '.')
        return c;
    
    if (isdigit(c))
        while (isdigit(*++s = c = getch()))
            ;
    
    if (c == '.')
        while(isdigit(*++s = c = getch()))
            ;
    
    *s = '\0';

    if (c != EOF)
        ungetch(c);
    
    return 0;
}