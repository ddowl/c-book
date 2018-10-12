/*
  WRite versions of the library functions strncpy, strncat, and strncmp, which
  operate on at most the first n characters of their argument strings. For
  example, strncpy(s, t, n) copies at most n characters of t to s. Full
  descriptions are in Appendix B.
*/

#include <stdio.h>
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
}

/*
  concatenate at most n characters of string ct to string
  s, terminate s with '\0'; return s
*/
char *strNcat(char *s, char *ct, int n) {

}

/*
  compare at most n characters of string cs to string ct;
  return < 0 if cs < ct, 0 if cs == ct, or > 0 if cs > ct.
*/
int strNcmp(char *cs, char *ct, int n) {

}

int main() {
  printf("Testing strncpy...\n");
  printf("Testing strncat...\n");
  printf("Testing strncmp...\n");
}