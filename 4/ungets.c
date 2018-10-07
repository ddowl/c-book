/*
  Write a routine ungets(s) that will push back an entire string
  onto the input. Should ungets know about buf and bufp, or should
  it just use ungetch?
*/

#include <stdio.h>
#include <string.h>

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

void ungets(char s[]) {
  for (int i = 0; i < strlen(s); i++) {
    ungetch(s[i]);
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

int main() {
  resetBuf();
  printBuf();

  resetBuf();
  ungets("here's a string!");
  printBuf();
}