#include <stdio.h>

int main() {
  int c1;
  int c2;

  c1 = getchar();
  if (c1 != EOF) {
    putchar(c1);
  }

  while ((c2 = getchar()) != EOF) {
    if (c1 != ' ' || c2 != ' ') {
      putchar(c2);
    }
    c1 = c2;
  }
}