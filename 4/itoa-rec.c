 /*
  Adapt the ideas of printd to write a recursive version of itoa;
  that is, convert an integer into a string by calling a recursive
  routine.
*/

/*
  In a two's complement number representation, our version of itoa
  does not handle the largest negative number, that is, the value of
  n equal to -2^(wordsize - 1). Explain why not. Modify it to print
  that value correctly, regardless of the machine on which it runs.

  it looks like -(__INT_MAX__+1) == __INT_MAX__+1
  this is because there is no negative equivalent to INT_MAX+1 in a twos
  complement system.
*/

#include "../1/reverse.c"
#include <stdio.h>
#define SUFFICIENT_BUFFER_LEN 100

void itoa(int n, char s[]) {
  int i, sign;

  if ((sign = n) < 0) {
    n = -n;
  }

  i = 0;
  do {
    s[i++] = n % 10 + '0';
  } while ((n /= 10) > 0);

  if (sign < 0) {
    s[i++] = '-';
  }

  s[i] = '\0';
  reverse(s);
}

int itoaRecHelper(int n, char s[], int idx) {
  char nextDigit = n % 10 + '0';
  s[idx] = nextDigit;
  if (n / 10 > 0) {
    return itoaRecHelper(n / 10, s, idx + 1);
  } else {
    return idx + 1;
  }
}

void itoaRec(int n, char s[]) {
  int i, sign;

  if ((sign = n) < 0) {
    n = -n;
  }

  i = itoaRecHelper(n, s, 0);

  if (sign < 0) {
    s[i++] = '-';
  }
  s[i] = '\0';
  reverse(s);
}

void printItoaRec(int n, char buf[]) {
  itoaRec(n, buf);
  printf("itoa(%d) = %s\n", n, buf);
}

int main() {
  char buf[SUFFICIENT_BUFFER_LEN];
  printItoaRec(0, buf);
  printItoaRec(1, buf);
  printItoaRec(-1, buf);
  printItoaRec(100, buf);
  printItoaRec(-100, buf);
  printItoaRec(12345678, buf);
  printItoaRec(__INT_MAX__, buf);
}