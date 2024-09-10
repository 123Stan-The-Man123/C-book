#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>  /* for  atof() */
#include <string.h>

#define MAXOP   100  /* max size of operand or operator */
#define NUMBER  '0'  /* signal that a number was found */
#define COMMAND '1'
#define VARIABLE '2'
#define MAXVAL  100  /* maximum depth of val stack */
#define BUFSIZE 100
#define DEGREES (M_PI / 180)

int sp = 0;          /* next free stack position */
double val[MAXVAL];  /* value stack */
char buf[BUFSIZE];    /* buffer for ungetch */
int bufp = 0;         /* next free position in buf */
int command = 0;
double variables[26] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

int getop(char []);
void push(double);
double pop(void);
void commands(char s[]);
void variable(char c);
int getch(void);
void ungetch(int);

/* reverse Polish calculator */
int main(void) {
    int type;
    double op2;
    char s[MAXOP];

while ((type = getop(s)) != EOF) {
    switch (type) {
        case NUMBER:
            push(atof(s));
            break;
        
        case COMMAND:
            commands(s);
            break;
        
        case VARIABLE:
            variable(s[0]);
            break;

        case '+':
            push(pop() + pop());
            break;

        case '*':
            push(pop() * pop());
            break;

        case '-':
            op2 = pop();
            push(pop() - op2);
            break;

        case '/':
            op2 = pop();
            if (op2 != 0.0)
                push(pop() / op2);

            else
                printf("error: zero divisor\n");

            break;
        
        case '%':
            op2 = pop();
            if (op2 != 0)
                push((long) pop() % (long) op2);
                
            else
                printf("error: zero divisor\n");
            
            break;

        case '\n':
            if(command)
                command = 0;
            else
                printf("\t%.8g\n", pop());
            
            break;
            
        default:
            printf("error: unknown command %s\n", s);
            break;
        }
    }
        
    return 0;
}
   
/* push:  push f onto value stack */
void push(double f) {
    if (sp < MAXVAL)
        val[sp++] = f;
    else
        printf("error: stack full, can't push %g\n", f);
}

/* pop:  pop and return top value from stack */
double pop(void) {
    if (sp > 0)
        return val[--sp];

    else {
        printf("error: stack empty\n");
        return 0.0;
    }
}
   
/* getop:  get next character or numeric operand */
int getop(char s[]) {
    int i, c, temp;
    while ((s[0] = c = getch()) == ' ' || c == '\t')
        ;
       
    s[1] = '\0';
       
    if ((!isdigit(c) && !isalpha(c)) && c != '.' && c != '-')
        return c;      /* not a number */
    
    i = 0;

    if (isalpha(c)) {
        do {
            s[i++] = c;
            c = getch();
        } while(isalpha(c));

        s[i] = '\0';
        ungetch(c);

        return (strlen(s) == 1) ? VARIABLE : COMMAND;
    }

    if (c == '-') {
        temp = c;
        c = getch();

        if (isdigit(c)) {
            s[i++] = temp;
            s[i] = c;
        }

        else {
            return temp;
        }
    }
    
    if (isdigit(c))    /* collect integer part */
        while (isdigit(s[++i] = c = getch()))
            ;
       
    if (c == '.')      /* collect fraction part */
        while (isdigit(s[++i] = c = getch()))
            ;
    
    s[i] = '\0';
    
    if (c != EOF)
        ungetch(c);
    
    return NUMBER;
}

int getch(void) {     /* get a (possibly pushed-back) character */
    return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c) { /* push character back on input */
    if (bufp >= BUFSIZE)
        printf("ungetch: too many characters\n");
       
    else
        buf[bufp++] = c;
}

void commands(char s[]) {
    int position, op2;
    
    if (!strcmp(s, "print")) {
        if (sp > 0) {
            position = sp - 1;

            for (; position >= 0; --position) {
                printf("%lf\n", val[position]);
            }
        }

        else {
            printf("error: stack empty\n");
        }

        command = 1;
    }

    else if (!strcmp(s, "duplicate")) {
        if (sp > 0) {
            position = sp;

            for (int i = 0; i < position && sp < MAXVAL; i++, sp++) {
                val[sp] = val[i];
            }
        }

        else {
            printf("error: stack empty\n");
        }

        command = 1;
    }

    else if (!strcmp(s, "swap")) {
        if (sp > 0) {
            op2 = val[sp - 1];

            val[sp - 1] = val[sp - 2];
            val[sp -2] = op2;
        }
            
        else {
            printf("error: stack empty\n");
        }

        command = 1;
    }

    else if (!strcmp(s, "clear")) {
        sp = 0;

        command = 1;
    }

    else if (!strcmp(s, "sin")) 
        push(sin(pop() * DEGREES));
    
    else if (!strcmp(s, "cos"))
        push(cos(pop() * DEGREES));
    
    else if (!strcmp(s, "tan")) {
        op2 = pop();

        if (op2 % 90 == 0) {
            printf("undefined\n");
            command = 1;
        }
        
        else
            push(tan(op2 * DEGREES));
    }

    else if (!strcmp(s, "exp"))
        push(exp(pop()));
    
    else if (!strcmp(s, "pow")) {
        op2 = pop();
        push(pow(pop(), op2));
    }

    else {
        printf("error: unknown command %s\n", s);
    }

    return ;
}

void variable(char c) {
    int type;
    int index = (isupper(c)) ? c - 'A' : c - 'a';
    char s[MAXOP];
    
    if ((type = getop(s)) == '=')
        variables[index] = pop();
    
    else
        ungetch(s[0]);

    push(variables[index]);
    
    return ;
}
