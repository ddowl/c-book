/*
  Write the function any(s1, s2), which returns the first location
  in the string s1 where any character from the string s2 occurs, or -1
  if s1 contains no characters from s2. (The standard library function
  strpbrk does the same  job but returns a pointer to the location.)
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

int any(char s1[], char s2[]) {
  for (int i = 0; i < strlen(s1); i++) {
    if (includes(s1[i], s2)) {
      return i;
    }
  }
  return -1;
}

int main() {
  char noMatchingChars1[] = "123456789";
  char noMatchingChars2[] = "abcdefghi";

  char oneMatchingChar1[] = "cat";
  char oneMatchingChar2[] = "kit";

  char severalMatchingChars1[] = "racecar";
  char severalMatchingChars2[] = "red";

  printf("%s %s\n", noMatchingChars1, noMatchingChars2);
  printf("%d\n", any(noMatchingChars1, noMatchingChars2));

  printf("%s %s\n", oneMatchingChar1, oneMatchingChar2);
  printf("%d\n", any(oneMatchingChar1, oneMatchingChar2));


  printf("%s %s\n", severalMatchingChars1, severalMatchingChars2);
  printf("%d\n", any(severalMatchingChars1, severalMatchingChars2));

}