#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>  /* for  atof() */

#define MAXOP   100  /* max size of operand or operator */
#define NUMBER  '0'  /* signal that a number was found */
#define MAXVAL  100  /* maximum depth of val stack */
#define BUFSIZE 100
   
int sp = 0;          /* next free stack position */
double val[MAXVAL];  /* value stack */
char buf[BUFSIZE];    /* buffer for ungetch */
int bufp = 0;         /* next free position in buf */

int getop(char []);
void push(double);
double pop(void);
int getch(void);
void ungetch(int);

/* reverse Polish calculator */
int main(void) {
    int type, position, command;
    command = 0;
    double op2;
    char s[MAXOP];

while ((type = getop(s)) != EOF) {
    switch (type) {
        case NUMBER:
            push(atof(s));
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
        
        case 'p':
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

            break;
        
        case 'd':
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

            break;
        
        case 's':
            if (sp > 0) {
                op2 = val[sp - 1];

                val[sp - 1] = val[sp - 2];
                val[sp -2] = op2;
            }
            
            else {
                printf("error: stack empty\n");
            }

            command = 1;

            break;
        
        case 'c':
            sp = 0;
            command = 1;

            break;

        case '\n':
            if (!(command)) 
                printf("\t%.8g\n", pop());
            else
                command = 0;
            
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
       
    if (!isdigit(c) && c != '.' && c != '-')
        return c;      /* not a number */
    
    i = 0;

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