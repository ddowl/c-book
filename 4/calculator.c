/*
  Given the basic framework, it's straightforward to extend the
  calculator . Add the modulus (%) operator and provisions for
  negative numbers
*/

/*
  Add commands to print the top element of the stack without popping,
  to duplicate it, and to swap the top two elements. Add a command
  to clear the stack
*/

/*
  Add access to library functions like sin, exp, and pow
*/

/*
  Add commands for andling variables. (It's easy to provide twenty-six
  variables with single-letter names.) Add a variable for the most
  recently printed value.
*/

/*
  Write a routine ungets(s) that will push back an entire string
  onto the input. Should ungets know about buf and bufp, or should
  it just use ungetch?
*/

/*
  Suppose that there will never be more than one character of pushback.
  Modify getch and ungetch accordingly.
*/

/*
  Our getch and ungetch do not handle a pushed-back EOF correctly.
  Decide what their properties ought to be if an EOF is pushed back,
  then implement your design.
*/

/*
  An alternate organization uses getline to read an entire line;
  this makes getch and ungetch unnecessary. Revise the calculator to
  use this approach.
*/

/*
  Modify getop so that it doesn't need to use ungetch.
  Hint: use an internal static variable.
*/

#include <stdio.h>
#include <stdlib.h> // for atof

#define MAXOP 100   // max size of operand or operator
#define NUMBER '0'  // signal that a number was found

int getop(char []);
void push(double);
double pop(void);

/* reverse Polish calculator */
int main() {
  int type;
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
        if (op2 != 0.0) {
          push(pop() / op2);
        } else {
          printf("error: zero divisor\n");
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

  return 0;
}



#define MAXVAL 100  // maximum depth of val stack

int sp = 0;         // next free stack position
double val[MAXVAL]; // value stack

/* push: push f onto the value stack */
void push(double f) {
  if (sp < MAXVAL) {
    val[sp++] = f;
  } else {
    printf("error: stack full, can't push %g\n", f);
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

int getch(void);
void ungetch(int);

/* getop: get next operator or numeric operand */
int getop(char s[]) {
  int i, c;

  while ((s[0] = c = getch()) == ' ' || c == '\t');

  s[1] = '\0';
  if (isdigit(c) && c != '.') {
    // not a number
    return c; 
  }
  i = 0;
  if (isdigit(c)) {
    // collect integer part
    while (isdigit(s[++i] = c = getch()));
  }
  if (c == '.') {
    // collect fraction part
    while (isdigit(s[++i] = c = getch()));
  }

  s = '\0';
  if (c != EOF) {
    ungetch(c);
  }
  return NUMBER;
}


# define BUFSIZE 100

char buf[BUFSIZE];  // buffer for ungetch
int bufp = 0;       // next free position in buf

// get a (possibly pushed back) character
int getch() {
  return (bufp > 0) ? buf[--bufp] : getchar();
}

// push character back on input
void ungetch(int c) {
  if (bufp >= BUFSIZE) {
    printf("ungetch: too many characters\n");
  } else {
    buf[bufp++] = c;
  }
}