#include <stdio.h>
#include <string.h>

#define BUFSIZE 10000
#define MAXLINES 5000     /* max #lines to be sorted */

char *lineptr[MAXLINES];  /* pointers to text lines */

int readlines(char *lineptr[], int nlines, char buffer[]);
void writelines(char *lineptr[], int nlines);
void qsort(char *lineptr[], int left, int right);

/* sort input lines */
int main(void) {
    int nlines;     /* number of input lines read */
    static char buffer[BUFSIZE];

    if ((nlines = readlines(lineptr, MAXLINES, buffer)) >= 0) {
        qsort(lineptr, 0, nlines-1);
        writelines(lineptr, nlines);

        return 0;
    } else {
        printf("error: input too big to sort\n");
        return 1;
    }
}

#define MAXLEN 1000  /* max length of any input line */

/* getline:  read a line into s, return length  */
int my_getline(char s[],int lim) {
    int c, i;

    for (i=0; i < lim-1 && (c=getchar())!=EOF && c!='\n'; ++i)
        s[i] = c;
       
    if (c == '\n') {
        s[i] = c;
        ++i;
    }

    s[i] = '\0';
    return i;
}

int my_getline(char *, int);
char *alloc(int);

/* readlines:  read input lines */
int readlines(char *lineptr[], int maxlines, char buffer[]) {
    int len, nlines;
    char *p, line[MAXLEN];
    char *bufp = buffer;
    nlines = 0;

    while ((len = my_getline(line, MAXLEN)) > 0) {
        if (buffer + BUFSIZE - bufp >= len) {
            bufp += len;

            p = bufp - len;
        }
        
        else {
            p = 0;
        }

        if (nlines >= maxlines || p == NULL)
            return -1;
        
        else {
            line[len-1] = '\0';  /* delete newline */
            strcpy(p, line);
            lineptr[nlines++] = p;
        }
    }
    
    return nlines;
}

/* writelines:  write output lines */
void writelines(char *lineptr[], int nlines) {
    while (nlines -- > 0)
        printf("%s\n", *lineptr++);
}

/* qsort:  sort v[left]...v[right] into increasing order */
void qsort(char *v[], int left, int right) {
    int i, last;
    void swap(char *v[], int i, int j);

    if (left >= right)  /* do nothing if array contains */
        return;         /* fewer than two elements */
    
    swap(v, left, (left + right)/2);
    last = left;

    for (i = left+1; i <= right; i++)
        if (strcmp(v[i], v[left]) < 0)
            swap(v, ++last, i);
       
    swap(v, left, last);
    qsort(v, left, last-1);
    qsort(v, last+1, right);
}

/* swap:  interchange v[i] and v[j] */
void swap(char *v[], int i, int j) {
    char *temp;

    temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}