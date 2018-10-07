/*
  Suppose that there will never be more than one character of
  pushback. Modify getch and ungetch accordingly.
*/

#include <stdio.h>
#include <string.h>

char buf;         // buffer for ungetch
int bufIsSet = 0; // whether the buf is occupied

int getch() {    // get a (possibly pushed back) character
  char c;
  if (bufIsSet) {
    c = buf;
    bufIsSet = 0;
  } else {
    c = getchar();
  }
  return c;
}

void ungetch(int c) { // push back on input
  if (bufIsSet) {
    printf("ungetch: character is already saved\n");
  } else {
    buf = c;
    bufIsSet = 1;
  }
}

// Test Helpers

void printBuf() {
  printf("buf: %c, bufIsSet: %d\n", buf, bufIsSet);
}

void clearBuf() {
  bufIsSet = 0;
}

int main() {
  clearBuf();
  printBuf();

  ungetch('a');
  printBuf();

  char c = getch();
  printf("getch() = %c\n", c);
  printBuf();
}