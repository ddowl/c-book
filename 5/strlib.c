/*
  Write versions of the library functions strncpy, strncat, and strncmp, which
  operate on at most the first n characters of their argument strings. For
  example, strncpy(s, t, n) copies at most n characters of t to s. Full
  descriptions are in Appendix B.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
  copy at most n characters of string ct to s; return s.
  Pad with '\0's if t has fewer than n charcters.
*/
char *strNcpy(char *s, char *ct, int n) {
  int sLen = strlen(s);
  for (int i = 0; i < n; i++) {
    s[i] = ct[i];
  }
  if (n < sLen) {
    for (int i = n; i < sLen; i++) {
      s[i] = '\0';
    }
  } else {
    s[n] = '\0';
  }
  return s;
}

/*
  concatenate at most n characters of string ct to string
  s, terminate s with '\0'; return s
*/
char *strNcat(char *s, char *ct, int n) {
  int sLen = strlen(s);
  char *cat = malloc(sLen + n);
  strcpy(cat, s);
  strNcpy(cat + sLen, ct, n);
  return cat;
}

/*
  compare at most n characters of string cs to string ct;
  return < 0 if cs < ct, 0 if cs == ct, or > 0 if cs > ct.
*/
int strNcmp(char *cs, char *ct, int n) {
  int i;
  for (i = 0; i < n && cs[i] != '\0' && ct[i] != '\0'; i++) {
    if (cs[i] != ct[i]) {
      if (cs[i] < ct[i]) {
        return -1;
      } else {
        return 1;
      }
    }
  }
  return i == n ? 0 : cs[i] - ct[i];
}

void printStrNCpy(char *s, int n) {
  char buf[100];
  printf("strncpy(%s, %d) = ", s, n);
  char *copy = strNcpy(buf, s, n);
  printf("%s\n", copy);
}

void printStrNCat(char *a, char *b, int n) {
  char buf[100];
  strcpy(buf, a);
  printf("strncat(%s, %s, %d) = ", buf, b, n);
  char *cat = strNcat(buf, b, n);
  printf("%s\n", cat);
}

void printStrNCmp(char *a, char *b, int n) {
  printf("strncmp(%s, %s, %d) = ", a, b, n);
  int cmp = strNcmp(a, b, n);
  printf("%d\n", cmp);
}

int main() {
  printf("Testing strncpy...\n");
  printStrNCpy("potato", 6);
  printStrNCpy("potato", 10);
  printStrNCpy("potato", 3);
  printf("\n");
  
  printf("Testing strncat...\n");
  printStrNCat("potato ", "cheese", 6);
  printStrNCat("potato ", "cheese", 10);
  printStrNCat("potato ", "cheese", 3);
  printf("\n");

  printf("Testing strncmp...\n");
  printStrNCmp("potato", "potato", 6);
  printStrNCmp("potato", "potato", 10);
  printStrNCmp("potato", "potato", 3);
  printStrNCmp("potato", "pottery", 3);
  printStrNCmp("potato", "pottery", 4);
  printStrNCmp("potato", "pot", 4);
  printf("\n");
}