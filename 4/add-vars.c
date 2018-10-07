/*
  Add access to library functions like sin, exp, and pow. See
  <math.h> in Appendix B, Section 4.
*/

#include <stdio.h>
#include <stdlib.h>  // for atof()
#include <math.h>    // for fmod()
#include <ctype.h>

#define MAXOP 100    // max size of operand or operator
#define NUMBER '0'   // signal that a number wes found

int getop(char []);
void push(double);
double pop();

/* reverse Polish calculator */
int main() {
  int type;
  double op2;
  char s[MAXOP];
  double vars[26];    // vars will only consist of lowercase letters
  int varSet[25];     // will indicate that variable is set
  double lastPrinted = 0.0;

  while ((type = getop(s)) != EOF) {
    switch (type) {
      case NUMBER:
        push(atof(s));
        break;
      case '+':
        push(pop() + pop());
        break;
      case '-':
        op2 = pop();
        push(pop() - op2);
        break;
      case '*':
        push(pop() * pop());
        break;
      case '/':
        op2 = pop();
        if (op2 != 0.0)
          push(pop() / op2);
        break;
      case '%':
        op2 = pop();
        if (op2 != 0)
          {
            push(fmod(pop(), op2));
          }
        break;
      case '\n':
        lastPrinted = pop();
        printf("\t%.8g\n", lastPrinted);
        break;
      case '#':
        printf("\t%.8g\n", lastPrinted);
        break;
      default:
        if (isalpha(type)) {
          int i = type - 'a';
          if (varSet[i]) {
            push(vars[i]);
          } else {
            vars[i] = pop();
            varSet[i] = 1;
          }
        }
        break;
    }
  }
  return 0;
}

#define MAXVAL 100

int sp = 0;
double val[MAXVAL];

/* push: push f onto value stack */
void push(double f) {
  if (sp < MAXVAL) {
    val[sp++] = f;
  } else {
    printf("error: stack full, con't push %g\n", f);
  }
}

/* pop: pop and return top value from stack */
double pop() {
  if (sp > 0) {
    return val[--sp];
  } else {
    printf("error: stack empty\n");
    return 0.0;
  }
}

#include <ctype.h>

int getch();
void ungetch(int);

/* getop: get next operator or numberic operand */
int getop(char s[]) {
  int i, c;

  while ((s[0] = c = getch()) == ' ' || c == '\t')
    ;
  s[1] = '\0';
  if (!isdigit(c) && c != '.')
    return c;                  // not a number
  i = 0;
  if (isdigit(c))              // collect integer part
    while (isdigit(s[++i] = c = getch()))
      ;
  if (c == '.')                // collect fraction part
    while (isdigit(s[++i] = c = getch()))
      ;
  s[i] = '\0';
  if (c != EOF)
    ungetch(c);
  return NUMBER;
}

#define BUFFSIZE 100

char buf[BUFFSIZE];  // buffer for ungetch
int bufp = 0;        // next free position in buf

int getch() {    // get a (possibly pushed back) character
  return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c) { // push back on input
  if (bufp >= BUFFSIZE)
    printf("ungetch: too many characters\n");
  else buf[bufp++] = c;
}