#include <stdio.h>
#include <string.h>

#define MAXLINE 1000

// read a line into s, return length
int getLine(char s[], int lim) {
  int c, i;

  c = getchar();
  for (i = 0; i < lim - 1 && c != EOF && c != '\n'; ++i) {
    s[i] = c;
    c = getchar();
  }
  if (c == '\n') {
    s[i] = c;
    ++i;
  }
  s[i] = '\0';
  return i;
}

// consume a line from input stream, saving the first lim chars into s
int consumeLine(char s[], int lim) {
  int lineLen, len;
  lineLen = len = getLine(s, MAXLINE);
  char tempBuf[MAXLINE];
  while (len == MAXLINE - 1) {
    len = getLine(tempBuf, MAXLINE);
    lineLen += len;
  }
  return lineLen;
}

// removes all comments from a C program.
// Don't forget to handle quoted strings and character constants properly.
int main() {
  int len = 0;            // current line length
  char line[MAXLINE];     // current input line

  while ((len = consumeLine(line, MAXLINE)) > 0) {

  }
  return 0;
}