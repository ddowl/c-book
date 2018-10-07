/*
  MOdify getop so that it doesn't need to use ungetch. Hint:
  use an internal static variable.a
*/

#include <stdio.h>
#define NUMBER '0'   // signal that a number wes found

int getop(char []);

int main() {

}

#include <ctype.h>

int getch();

/* getop: get next operator or numberic operand */
int getop(char s[]) {
    int i, c;
    static char buf = EOF;

    if (buf == EOF || buf == ' ' || buf == '\t') {
      while ((s[0] = c = getch()) == ' ' || c == '\t')
        ;
      s[1] = '\0';
    } else {
      c = buf;
    }
    if (!isdigit(c) && c != '.')
      return c;   /* not a number */
    i = 0;
    if (isdigit(c)) /* collect integer part */
      while (isdigit(s[++i] = c = getch()))
        ;
    if (c == '.')   /* collect fraction part */
      while (isdigit(s[++i] = c = getch()))
        ;
    s[i] = '\0';
    if (c != EOF)
        buf = c;
    return NUMBER;
}

#define BUFFSIZE 100

char buf[BUFFSIZE];  // buffer for ungetch
int bufp = 0;        // next free position in buf

int getch() {    // get a (possibly pushed back) character
  return (bufp > 0) ? buf[--bufp] : getchar();
}