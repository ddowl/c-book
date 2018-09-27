#include <stdio.h>

#define CHARSET_SIZE 256 // for ASCII

int main() {
  int c;

  int charFreqs[CHARSET_SIZE];
  // init with 0s
  for (int i = 0; i < CHARSET_SIZE; ++i) {
    charFreqs[i] = 0;
  }

  while ((c = getchar()) != EOF) {
    ++charFreqs[c];
  }

  // print histogram
  printf("Character\tFrequency\n");
  for (int i = 0; i < CHARSET_SIZE; ++i) {
    if (charFreqs[i] != 0) {
      printf("%c\t\t%d\n", i, charFreqs[i]);
    }
  }
}