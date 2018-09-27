#include <stdio.h>

int main() {
  int c;

  c = getchar() != EOF;

  printf("c:   %d\n", c);
  printf("EOF: %d\n", EOF);
}