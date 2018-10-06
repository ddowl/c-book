/*
  In a two's complement number system, "x &= (x - 1)" deletes the
  rightmost 1-bit in x. Explain Why. Use this observation to write
  a faster version of bitcount.

  If x is odd, then (x-1) has the same bit representation as x except 
  that the rightmost 1-bit is now a 0. In this case, (x & (x-1)) == (x-1).

  If x is even, then the representation of (x-1) has the rightmost zeros 
  of x becoming ones and the rightmost one becoming a zero. Anding the two
  clears the rightmost 1-bit in x and all the rightmost 1-bits from (x-1).
*/

#include <time.h>
#include <stdio.h>

/* bitcount:  count 1 bits in x */
int bitcount(unsigned x)
{
    int b = 0;
    while (x != 0) {
      if (x & 01) { b++; }
      x >>= 1;
    }
    return b;
}

/* bitcount: count 1 bits in x but _faster_ */
int fastBitcount(unsigned x) {
  int b = 0;
  while (x != 0) {
    b++;
    x &= x - 1;
  }
  return b;
}

void measureFunc(int (*func)(unsigned)) {
  // Calculate the time taken by fun() 
  clock_t t; 
  t = clock();
  for (unsigned i = 0; i < 1000000; i++) {
    (*func)(i);
  }
  t = clock() - t; 
  double time_taken = ((double)t)/CLOCKS_PER_SEC; // in seconds 

  printf("func() took %f seconds to execute \n", time_taken); 
}

int main() {
  unsigned x = 374659;
  printf("bitcount(0x%x) = %d\n", x, bitcount(x));
  printf("fastBitcount(0x%x) = %d\n", x, fastBitcount(x));
  printf("Timing bitcount...\n");
  measureFunc(bitcount);
  printf("Timing fastBitcount...\n");
  measureFunc(fastBitcount);
}