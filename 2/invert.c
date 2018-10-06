/*
  Write a function invert(x, p, n) that returns x with the n bits
  that begin at position p inverted (i.e. 1 changed into 0 and vice
  versa), leaving the others unchanged
*/

#include <stdio.h>

int invert(unsigned x, int p, int n) {
  int mask = ~(~0 << n) << (p - n + 1);
  return x ^ mask;
}

int main() {
  unsigned x = 0xd;
  int p = 2;
  int n = 2;
  unsigned k = invert(x, p, n);
  printf("invert(0x%x, %d, %d) = 0x%x\n", x, p, n, k);
}