/*
  Write the function htoi(s), which converts a string of hex
  digits (including an optional 0x or 0X) into ist equivalent
  integer value. The allowable digits are 0 through 9, a through
  f, and A through F.
*/

#include <stdio.h>
#include <string.h>

int isDigit(char c) {
  return c >= 48 && c <= 57;
}

int isLowerHexLetter(char c) {
  return c >= 97 && c <= 102;
}

int isUpperHexLetter(char c) {
  return c >= 65 && c <= 70;
}

int isHex(char c) {
  return isDigit(c) || isLowerHexLetter(c) || isUpperHexLetter(c);
}

// maps the character to its digit as an integer
// if not a hex digit, returns -1
int charToHexDigit(char c) {
  if (isDigit(c)) {
    return c - 48;
  } else if (isLowerHexLetter(c)) {
    return c - 97 + 10;
  } else if (isUpperHexLetter(c)) {
    return c - 65 + 10;
  } else {
    return -1;
  }
}

int htoi(char s[]) {
  int res = 0;
  int product = 1;
  int sign = 1;
  
  for (int i = strlen(s) - 1; i >= 0; i--) {
    // printf("%c\n", s[i]);
    int digit = charToHexDigit(s[i]);
    if (digit != -1) {
      res += product * digit;
      product *= 16;
    } else if (s[i] == 'x' || s[i] == 'X') {
      continue;
    } else if (i == 0 && s[i] == '-') {
      res *= -1;
    } else {
      // invalid hex digit
      return -1;
    }
  }

  return res;
}

int main() {
  char sixteen[] = "10";
  char increasing[] = "12345";
  char startsWithZeroX[] = "0x1";
  char negative[] = "-1";
  char negativeWithX[] = "-0x1";
  char letters[] = "abcdefABCDEF";
  char stdfmt[] = "%s %d\n";

  printf(stdfmt, sixteen, htoi(sixteen));
  printf(stdfmt, increasing, htoi(increasing));
  printf(stdfmt, startsWithZeroX, htoi(startsWithZeroX));
  printf(stdfmt, negative, htoi(negative));
  printf(stdfmt, negativeWithX, htoi(negativeWithX));
  printf(stdfmt, letters, htoi(letters));
}