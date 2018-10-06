/*
  Write a function setbits(x, p, n, y) that returns x with the 
  n bits that begin at position p set to the rightmost n bits of y,
  leaving the other bits unchanged.
*/

#include <stdio.h>

int setbits(unsigned x, int p, int n, unsigned y) {
  unsigned rightNBitsOfY = (y & ~(~0 << n));
  printf("rightNBitsOfY = 0x%x\n", rightNBitsOfY);
  // printf("0x%x\n", 3 << -1);
  unsigned zeroNBitsOfXAtP = (x & ~(~(~0 << n) << (p - n + 1)));
  printf("zeroNBitsOfXAtP = 0x%x\n", zeroNBitsOfXAtP);
  return (zeroNBitsOfXAtP | (rightNBitsOfY << (p - n + 1)));
}

int main() {
  unsigned i = 0xf;
  unsigned j = 0x5;
  int p = 2;
  int n = 3;
  unsigned k = setbits(i, p, n, j);
  printf("setbits(0x%x, %d, %d, 0x%x) = 0x%x\n", i, p, n, j, k);
}