#include <stdio.h>
#define YES 1
#define NO 0

int left_brackets = 0;
int right_brackets = 0;
int left_braces = 0;
int right_braces = 0;
int left_quote = 0;
int right_quote = 0;

void get_characters(void);
char ignore_quotes(char quote);
char ignore_comments(char c);
int check_characters(void);

int main(void) {
    get_characters();
    int result = check_characters();

    if (result == 0) {
        printf("No mistakes.\n");
    }

    else if (result == 1) {
        printf("Missing \')\'\n");
    }

    else if (result == 2) {
        printf("Missing \'}\'\n");
    }

    else if (result == 3) {
        printf("Missing \' or \"");
    }

    return 0;
}

void get_characters(void) {
    int c;

    while ((c = getchar()) != EOF) {
        if (c == '(') {
            ++left_brackets;
        }

        else if (c == ')') {
            ++right_brackets;
        }

        else if (c == '{') {
            ++left_braces;
        }

        else if (c == '}') {
            ++right_braces;
        }

        else if ((c == '\'' || c == '\"')) {
            ++left_quote;
            c = ignore_quotes(c);
        }

        else if (c == '\\') {
            c = getchar();
        }

        else if (c == '/' && getchar() == '*') {
            c = ignore_comments(c);
        }

        else {
            ;
        }
    }
}

char ignore_quotes(char c) {
    int quote = c;

    while ((c = getchar()) != EOF) {
        if (c == quote) {
            ++right_quote;
            break;
        }
    }

    return c;
}

char ignore_comments(char c) {
    while ((c = getchar()) != EOF) {
        if (c == '*' && (c = getchar()) == '/') {
            break;
        }
    }

    return c;
}

int check_characters(void) {
    if (!(left_brackets == right_brackets)) {
        return 1;
    }

    else if (!(left_braces == right_braces)) {
        return 2;
    }

    else if (!(left_quote == right_quote)) {
        return 3;
    }

    else {
        return 0;
    }
}