/*
  Write a version of itoa that accepts three arguments instead of two.
  The third argument is a minimum field width; the converted number must
  be padded with blanks on the left if necessary to make it wide enough.
*/

#include "../1/reverse.c"
#include <stdio.h>
#define SUFFICIENT_BUFFER_LEN 100

void paddedItoa(int n, char s[], int minWidth) {
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

void printItoa(int n, char s[]) {
  int widths[] = {1, 3, 5, 10};
  for (int i = 0; i < 4; i++) {
    paddedItoa(n, s, widths[i]);
    printf("itob(%d, %d) = %s\n", n, widths[i], s);
  }
}

int main() {
  char buf[SUFFICIENT_BUFFER_LEN];
  printItoa(0, buf);
  printItoa(1, buf);
  printItoa(-1, buf);
  printItoa(100, buf);
  printItoa(-100, buf);
  printItoa(12345678, buf);
  printItoa(__INT_MAX__, buf);
}