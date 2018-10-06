/*
  Write the function itob(n, s, b) that converts the integer n into a base
  b character representation in the string s. In particular, itob(n, s, 16)
  formats n as a hexadecimal integer in s.
*/

#include "../1/reverse.c"
#include <stdio.h>
#define SUFFICIENT_BUFFER_LEN 100

void itob(int n, char s[], int b) {
  int i, sign;

  if ((sign = n) < 0) {
    n = -n;
  }

  i = 0;
  do {
    s[i++] = n % b + '0';
  } while ((n /= b) > 0);

  if (sign < 0) {
    s[i++] = '-';
  }

  s[i] = '\0';
  reverse(s);
}

void printItob(int n, char s[]) {
  int bases[] = {16, 10, 8, 2};
  for (int i = 0; i < 4; i++) {
    itob(n, s, bases[i]);
    printf("itob(%d, %d) = %s\n", n, bases[i], s);
  }
}

int main() {
  char buf[SUFFICIENT_BUFFER_LEN];
  
  printItob(16, buf);
  printItob(12345, buf);
  printItob(0xdeadbeef, buf);
}