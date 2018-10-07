/*
  Our geth and ungetch do not handle a pushed-back EOF correctly.
  Decide what their properties ought to be if an EOF is pushed
  back, then implement your design.

  If EOF is reached, don't accept anymore input push back.
  Don't include EOF in push back buffer.
*/

#include <stdio.h>
#include <string.h>

#define BUFFSIZE 100

char buf[BUFFSIZE];  // buffer for ungetch
int bufp = 0;        // next free position in buf
int eofReached = 0;

int getch() {    // get a (possibly pushed back) character
  return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c) { // push back on input
  if (bufp >= BUFFSIZE) {
    printf("ungetch: too many characters\n");
  } else if (eofReached) {
    printf("ungetch: eof already reached. can't push back\n");
  } else if (c == EOF) {
    eofReached = 1;
  } else {
    buf[bufp++] = c;
  }
}

// Test Helpers

void printBuf() {
  printf("buf:");
  for (int i = 0; i < bufp; i++) {
    printf(" %c", buf[i]);
  }
  printf(", bufp: %d\n", bufp);
}

void pushSomeChars() {
  ungetch('a');
  ungetch('b');
  ungetch('c');
}

void clearBuf() {
  bufp = 0;
}

void resetBuf() {
  clearBuf();
  pushSomeChars();
}

void getchAndPrintBuf() {
  char c = getch();
  printf("getch() = %c\n", c);
  printBuf();
}

int main() {
  resetBuf();
  printBuf();

  resetBuf();
  ungetch(EOF);
  printBuf();

  getchAndPrintBuf();
  getchAndPrintBuf();
  getchAndPrintBuf();
  getchAndPrintBuf();
}