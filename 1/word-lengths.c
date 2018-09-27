#include <stdio.h>

#define IN 1
#define OUT 0
#define MAX_WORD_SIZE 100

int main() {
  int c;

  int inWord = OUT;
  int wordLen = 0;

  int lenFreqs[MAX_WORD_SIZE]; // assumes no word greater than MAX_WORD_SIZE chars (bad assumption)
  // init with 0s
  for (int i = 0; i < MAX_WORD_SIZE; ++i) {
    lenFreqs[i] = 0;
  }

  while ((c = getchar()) != EOF) {
    if (c == ' ' || c == '\t' || c == '\n') {
      // if we're encountering whitespace
      if (inWord) {
        // previously we were in a word
        inWord = OUT;
        ++lenFreqs[wordLen];
        wordLen = 0;
      }
    } else {
      // if we're encoutering a non-whitespace character
      if (!inWord) {
        // previously we were outside a word
        inWord = IN;
      }
      ++wordLen;
    }
  }

  // print histogram
  printf("Word Length\tFrequency\n");
  for (int i = 0; i < MAX_WORD_SIZE; ++i) {
    if (lenFreqs[i] != 0) {
      printf("%d\t\t%d\n", i, lenFreqs[i]);
    }
  }
}