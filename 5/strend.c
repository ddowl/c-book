/*
  Write the function strend(s, t), which returns 1 if the string t occurs at
  the end of the string s, and zero otherwise.
*/

#include <stdio.h>
#include <string.h>

int strend(char *s, char *t) {
  int sLen = strlen(s);
  int tLen = strlen(t);
  return strcmp(s + sLen - tLen, t) == 0;
}

void printStrEnd(char *s, char *t) {
  printf("'%s' is at the end of '%s': ", t, s);
  int endsWithT = strend(s, t);
  printf("%d\n", endsWithT);
}

int main() {
  printStrEnd("the cat in the hat", "hat");
  printStrEnd("i do not like green eggs and ham", "green eggs");
}