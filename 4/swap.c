/*
  Define a macro swap(t, x, y) that interchanges two
  arguments of type t. (Block structure will help.)
*/

#include <stdio.h>

#define swap(t, x, y) { t temp = x; x = y; y = temp; }

int main() {
  int x = 1;
  int y = 2;
  printf("x: %d, y: %d\n", x, y);
  swap(int, x, y);
  printf("x: %d, y: %d\n", x, y);

  char c = 'c';
  char d = 'd';
  printf("c: %c, d: %c\n", c, d);
  swap(char, c, d);
  printf("c: %c, d: %c\n", c, d);
}