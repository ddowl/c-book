/*
  Write a function rightrot(x, n) that returns the value of the
  integer x rotated to the right by n bit positions
*/

#include <stdio.h>

int rightrot(unsigned x, int n) {
  unsigned rightNBits = x & ~(~0 << n);
  return (x >> n) | (rightNBits << (32 - n));
}

int main() {
  unsigned x = 0xd;
  int n = 4;
  unsigned k = rightrot(x, n);
  printf("rightrot(0x%x, %d) = 0x%x\n", x, n, k);
}