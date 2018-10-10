/*
  Write getfloat, the floating-point analog of getint. What type does
  getfloat return as its function value?
*/

#include <ctype.h>
#include <stdio.h>

int getch(void);
void ungetch(int);

// getfloat: get next float from input into *pn
int getfloat(double *pn) {
  int c, sign;

  while (isspace(c = getch()));

  if (!isdigit(c) && c != EOF && c != '+' && c != '-') {
    ungetch(c);
    return 0;
  }
  sign = (c == '-') ? -1 : 1;
  if (c == '+' || c == '-') {
    c = getch();
  }
  if (!isdigit(c)) {
    ungetch(c);
    return 0;
  }
  for (*pn = 0; isdigit(c); c = getch()) {
    *pn = 10 * *pn + (c - '0');
  }
  if (c == '.') {
    c = getch();
    double frac = 0;
    for (int i = 1; isdigit(c); c = getch(), i++) {
      frac += (1 / (i * 10.0)) * (c - '0');
    }
    *pn += frac;
  }
  *pn *= sign;
  if (c != EOF) {
    ungetch(c);
  }
  return c;
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

int main() {
  double a;

  getfloat(&a);
  printf("%f\n", a);
}