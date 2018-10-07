/*
  Write a recursive version of the function reverse(s),
  which reverses the string s in place.
*/

#include <stdio.h>
#include <string.h>

void swap(char s[], int i, int j){
  char temp = s[i];
  s[i] = s[j];
  s[j] = temp;
}

void reverse(char s[]) {
  int len = strlen(s);
  for (int i = 0; i < len / 2; ++i) {
    swap(s, i, len - i - 1);
  }
}


void reverseRecHelper(char s[], int idx, int end) {
  if (idx >= end / 2) { return; }

  swap(s, idx, end - idx - 1);
  reverseRecHelper(s, idx + 1, end);
}

void reverseRec(char s[]) {
  int len = strlen(s);
  reverseRecHelper(s, 0, len);
}

void printReverseRec(char s[]) {
  char cpy[100];
  strcpy(cpy, s);
  printf("reverseRec(%s) = ", cpy);
  reverseRec(cpy);
  printf("%s\n", cpy);
}

int main() {
  printReverseRec("cat");
  printReverseRec("dog");
  printReverseRec("racecar");
  printReverseRec("the quick brown fox");
}