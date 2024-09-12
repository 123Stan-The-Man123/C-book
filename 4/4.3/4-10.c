#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>  /* for  atof() */
#include <string.h>

#define MAXLINE 1000
#define MAXOP   100  /* max size of operand or operator */
#define NUMBER  '0'  /* signal that a number was found */
#define COMMAND '1'
#define VARIABLE '2'
#define MAXVAL  100  /* maximum depth of val stack */
#define BUFSIZE 100
#define DEGREES (M_PI / 180)

int sp = 0;          /* next free stack position */
double val[MAXVAL];  /* value stack */
int command = 0;
double last_printed;
double variables[26] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
char input[MAXOP];
int position = 0;
int my_index = -1;

int getop(char []);
void push(double);
double pop(void);
int my_getline(char line[], int maxline);
void commands(char s[]);
void variable(char c);

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
        
            case '?':
                variable(s[0]);
                break;
            
            case '=':
                if (my_index == -1) {
                    printf("Invalid use of \'=\'\n");
                    break;
                }

                pop();

                variables[my_index] = pop();
                push(variables[my_index]);
                my_index = -1;
                break;

            case '\n':
                if(command)
                    command = 0;
            
                else {
                    last_printed = pop();
                    printf("\t%.8g\n", last_printed);
                }
            
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
   
/* getop: get next operator or numeric operand - getline version */
int getop(char s[])
{
	static int    i, len;                  /* note static in type */
	static char   line[MAXLINE];           /* note static in type */
	int           j; 

	if (i == len) {                        /* previous line read completely */
		len = my_getline(line, MAXLINE);
		if (!len)
			return EOF;
		i = 0;                             /* reset line index */
	}

	j = 0;
	while (isblank(line[i]))                /* skip blanks */
		++i;

	if (line[i] == '-' && isdigit(line[i + 1]))  /*  sign */
			s[j++] = line[i++];
	
	if (isalpha(line[i])) {                 /* math functions and variables */
		while (isalpha(line[i]))
			s[j++] = line[i++];
		s[j] = '\0';
		return (strlen(s) == 1) ? VARIABLE : COMMAND;
	}

	if (!isdigit(line[i]) && line[i] != '.')
		return line[i++];                   /* not a number */

	if (isdigit(line[i]))                   /* collect number */
		while (isdigit(line[i]))
			s[j++] = line[i++];

	if( line[i] == '.')                     /* collect fraction part */
		while (isdigit(line[i]))
			s[j++] = line[i++];

	s[j] = '\0';
	return NUMBER;
}

int my_getline(char s[], int lim) {
    int i, c;

    for (i = 0; i < lim-1 && (c = getchar()) != EOF && c != '\n'; i++)
        s[i] = c;
    
    if (c == '\n')
        s[i++] = c;
    
    s[i] = '\0';
    return i;
}

void commands(char s[]) {
    int position, op2;
    
    if (!strcmp(s, "print")) {
        if (sp > 0) {
            position = sp - 1;

            for (; position >= 0; --position) 
                printf("%lf\n", val[position]);
        }

        else 
            printf("error: stack empty\n");

        command = 1;
    }

    else if (!strcmp(s, "duplicate")) {
        if (sp > 0) {
            position = sp;

            for (int i = 0; i < position && sp < MAXVAL; i++, sp++) 
                val[sp] = val[i];
        }

        else 
            printf("error: stack empty\n");

        command = 1;
    }

    else if (!strcmp(s, "swap")) {
        if (sp > 0) {
            op2 = val[sp - 1];

            val[sp - 1] = val[sp - 2];
            val[sp -2] = op2;
        }
            
        else 
            printf("error: stack empty\n");

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

    else 
        printf("error: unknown command %s\n", s);

    return ;
}

void variable(char c) {
    if (c == '?') {
        push(last_printed);
        return ;
    }
    
    my_index = (isupper(c)) ? c - 'A' : c - 'a';
    char s[MAXOP];

    push(variables[my_index]);
    
    return ;
}
