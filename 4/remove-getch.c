/*
  An alternate organization uses getline to read an entire input line;
  this makes getch and ungetch unnecessary. Revise the calculator to
  use this approach.
*/

#include <stdio.h>
#include <stdlib.h>  // for atof()
#include <math.h>    // for fmod()

#define MAXOP 100    // max size of operand or operator
#define MAXLINE 1000 // max size of input line
#define NUMBER '0'   // signal that a number wes found

int getLine(char s[], int);
int getop(char [], char []);
void push(double);
double pop();

int lineIdx = 0;

/* reverse Polish calculator */
int main() {
  int type;
  double op2;
  char s[MAXOP];
  char line[MAXLINE];

  while (getLine(line, MAXLINE) > 0) {
    while ((type = getop(s, line)) != '\0') {
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
          push (pop() * pop());
          break;
        case '/':
          op2 = pop();
          if (op2 != 0.0)
            push (pop() / op2);
          break;
        case '%':
          op2 = pop();
          if (op2 != 0) {
            push(fmod(pop(), op2));
          }
          break;
        case '\n':
          printf("\t%.8g\n", pop());
          break;
        default:
          printf("error: unknown command %s\n", s);
          break;
      }
    }
    lineIdx = 0;
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

// getLine: get line into s, return length
int getLine(char s[], int lim) {
  int c, i;

  i = 0;
  while (--lim > 0 && (c = getchar()) != EOF && c != '\n') {
    s[i++] = c;
  }

  if (c == '\n') {
    s[i++] = c;
  }

  s[i] = '\0';
  return i;
}

#include <ctype.h>

/* getop: get next operator or numeric operand */
int getop(char s[], char line[]) {
  int i, c;

  while ((s[0] = c = line[lineIdx++]) == ' ' || c == '\t')
    ;
  s[1] = '\0';

  if (!isdigit(c) && c != '.')
    return c;                  // not a number
  i = 0;
  if (isdigit(c))              // collect integer part
    while (isdigit(s[++i] = c = line[lineIdx++]));
  if (c == '.')                // collect fraction part
    while (isdigit(s[++i] = c = line[lineIdx++]));
  s[i] = '\0';
  return NUMBER;
}