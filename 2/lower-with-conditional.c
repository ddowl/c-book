/*
  Rewrite the function "lower", which converts upper case letters
  to lower case, with a conditional expression instead of if-else
*/

#include <stdio.h>
#include <string.h>

int isUpper(char c) {
  return c >= 65 && c <= 90;
}

char lower(char c) {
  return isUpper(c) ? c + 32 : c;
}

void lowerString(char s[]) {
  for (int i = 0; i < strlen(s); i++) {
    s[i] = lower(s[i]);
  }
}

void printLowerString(char s[]) {
  printf("lower(%s) = ", s);
  lowerString(s);
  printf("%s\n", s);
}

int main() {
  char allLower[] = "abcdef";
  char mixed[] = "aBcDeF";
  char allUpper[] = "ABCDEF";

  printLowerString(allLower);
  printLowerString(mixed);
  printLowerString(allUpper);
}