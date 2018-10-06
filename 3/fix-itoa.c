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
  int isSmallestInt = 0;

  if ((sign = n) < 0) {
    if (n == __INT_MAX__+1) {
      n = n - 1;
      isSmallestInt = 1;
    } else {
      n = -n;
    }
  }

  i = 0;
  do {
    // printf("%d\n", n);
    s[i++] = n % 10 + '0';
  } while ((n /= 10) > 0);

  if (sign < 0) {
    s[i++] = '-';
  }

  if (isSmallestInt) {
    s[0] = s[0] + 1;
  }

  s[i] = '\0';
  reverse(s);
}

void printItoa(int n, char buf[]) {
  itoa(n, buf);
  printf("itoa(%d) = %s\n", n, buf);
}

int main() {
  printf("largest integer: %d\n", __INT_MAX__);
  printf("smallest integer: %d\n", __INT_MAX__+1);
  printf("- smallest integer: %d\n", -(__INT_MAX__+1));

  
  char buf[SUFFICIENT_BUFFER_LEN];
  printItoa(0, buf);
  printItoa(1, buf);
  printItoa(-1, buf);
  printItoa(100, buf);
  printItoa(-100, buf);
  printItoa(12345678, buf);
  printItoa(__INT_MAX__, buf);
  printItoa(__INT_MAX__+1, buf);
}