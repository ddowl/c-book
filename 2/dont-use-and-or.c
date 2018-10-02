#include <stdio.h>

#define TRUE 1

/*
  Write a loop equivalent to the given for loop without
  using && or ||.
*/
int main() {
  int lim;
  int c;
  char s[10];

  // given loop
  for (int i = 0; i < lim - 1 && (c = getchar()) != '\n' && c != EOF; ++i) {
    s[i] = c;
  }

  // equivalent loop
  for (int i = 0; TRUE; ++i) {
    if (i >= lim - 1) { break; }
    if ((c = getchar()) == '\n') { break; }
    if (c == EOF) { break; }

    s[i] = c;
  }
}