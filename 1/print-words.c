#include <stdio.h>

#define IN 1
#define OUT 0

int main() {
  int c;

  int inWord = OUT;
  while ((c = getchar()) != EOF) {
    if (c == ' ' || c == '\t' || c == '\n') {
      // if we're encountering whitespace
      if (inWord) {
        // previously we were in a word
        // reset our state and print a newline
        inWord = OUT;
        putchar('\n');
      }
    } else {
      // if we're encoutering a non-whitespace character
      if (!inWord) {
        // previously we were outside a word, so reset state
        inWord = IN;
      }
      putchar(c);
    }
  }
}