/* Because I think it's unrealistic to have a single variable as a buffer for 
something like this, I won't be restructuring the calculator just to accomodate it. 
So, here are the revised (and stupid :/) getch and ungetch functions. */

#include <stdio.h>

int buf = 0;

int getch(void);
void ungetch(int c);

int main(void) {
	ungetch('A');
	ungetch('B');
	printf ("%c\n", getch());
	ungetch('C');
	printf ("%c\n", getch());

	return 0;
}

int getch(void) { 
    int c;

    if (buf)
        c = buf;

    else
        c = getchar();
    
    buf = 0;
    return c;
}

void ungetch(int c) { /* push character back on input */
    if (buf)
        printf("error: too many characters\n");
    
    else
        buf = c;
}