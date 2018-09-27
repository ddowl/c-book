#include <stdio.h>

int main() {
  int c;
  long whitespaceCount = 0;

  while ((c = getchar()) != EOF) {
    if (c == '\n' || c == '\t' || c == ' ') {
      ++whitespaceCount;
    }
  }
  printf("whitespace from input: %ld\n", whitespaceCount);
}