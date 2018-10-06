/*
  Write a function expand(s1, s2) that expands shorthand notations like
  a-z in the string s1 into the equivalent complite list abc...xyz in s2.
  Allow for letters of either case and digits, and be prepared to handle cases
  like a-b-c and a-z0-9 and -a-z. Arrange that a leading or trailing "-" is 
  taken literally
*/

#include <stdio.h>
#include <string.h>
#define SUFFICIENT_BUFFER_LEN 100

int isDigit(char c) {
  return c >= 48 && c <= 57;
}

int isLowerLetter(char c) {
  return c >= 97 && c <= 122;
}

int isUpperLetter(char c) {
  return c >= 65 && c <= 90;
}

int rangeBoundsMatch(char start, char end) {
  return (isDigit(start) && isDigit(end)) ||
          (isLowerLetter(start) && isLowerLetter(end)) ||
          (isUpperLetter(start) && isUpperLetter(end));
}

void expand(char src[], char dest[]) {
  int len = strlen(src);
  int i, j;
  for (i = j = 0; i < strlen(src) - 1; i++, j++) {
    if (src[i+1] == '-') {
      if (i+2 != len) {
        char start = src[i];
        char end = src[i + 2];
        if (rangeBoundsMatch(start, end)) {
          char curr = start;
          while (curr <= end) {
            dest[j++] = curr++;
          }
          j--;
          i += 2;
        } else {
          dest[j] = src[i];
        }
      } else {
        dest[j] = '-';
      }
    } else {
      dest[j] = src[i];
    }
  }
  dest[j++] = src[i];
  dest[j] = '\0';
}

void printExpand(char src[], char dest[]) {
  expand(src, dest);
  printf("expand(%s) = %s\n", src, dest);
}

int main() {
  char alphabet[] = "a-z";
  char backwards[] = "z-a";
  char allChars[] = "a-zA-Z0-9";
  char transitive[] = "a-b-c";
  char leadingDash[] = "-a-z";
  char trailingDash[] = "a-z-";
  char mixed[] = "abc-l0-5mno-rS-Z6-9";
  char nonsense[] = "0-ab-9";
  char destBuf[SUFFICIENT_BUFFER_LEN];

  printExpand(alphabet, destBuf);
  printExpand(backwards, destBuf);
  printExpand(allChars, destBuf);
  printExpand(transitive, destBuf);
  printExpand(leadingDash, destBuf);
  printExpand(trailingDash, destBuf);
  printExpand(mixed, destBuf);
  printExpand(nonsense, destBuf);
}