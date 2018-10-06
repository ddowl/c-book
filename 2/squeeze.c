/*
  Write an alternate version of squeeze(s1, s2) that deletes
  each character in s1 that matches any character in the string s2.
*/

#include <stdio.h>
#include <string.h>

// returns 1 if char c is included in string s
// otherwise returns 0
int includes(char c, char s[]) {
  for (int i = 0; i < strlen(s); i++) {
    if (c == s[i]) {
      return 1;
    }
  }
  return 0;
}

void squeeze(char s1[], char s2[]) {
  int i, j;
  for (i = j = 0; s1[i] != '\0'; i++) {
    if (!includes(s1[i], s2)) {
      s1[j++] = s1[i];
    }
  }
  s1[j] = '\0';
}

int main() {
  char noMatchingChars1[] = "123456789";
  char noMatchingChars2[] = "abcdefghi";

  char oneMatchingChar1[] = "cat";
  char oneMatchingChar2[] = "kit";

  char severalMatchingChars1[] = "racecar";
  char severalMatchingChars2[] = "red";

  printf("%s %s\n", noMatchingChars1, noMatchingChars2);
  squeeze(noMatchingChars1, noMatchingChars2);
  printf("%s\n", noMatchingChars1);

  printf("%s %s\n", oneMatchingChar1, oneMatchingChar2);
  squeeze(oneMatchingChar1, oneMatchingChar2);
  printf("%s\n", oneMatchingChar1);

  printf("%s %s\n", severalMatchingChars1, severalMatchingChars2);
  squeeze(severalMatchingChars1, severalMatchingChars2);
  printf("%s\n", severalMatchingChars1);
}