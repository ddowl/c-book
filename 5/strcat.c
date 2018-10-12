/*
  Write a pointer version of the function strcat that we showed in Chapter 2.
  strcat(s, t): copies the string t to the end of s.
*/

#include <stdio.h>
#include <string.h>

void strCat(char *s, char *t) {
  while (*s != '\0') { s++; }
  while ((*s = *t) != '\0') { s++; t++; };
}

int main() {
  char s[100];
  char t[] = "this goes to the end of the other string!";
  strcpy(s, "This is a given string and ");
  strCat(s, t);
  printf("%s\n", s);
}