#include <stdio.h>
#include <string.h>

#define MAXLINE 1000
#define TAB_LEN 8

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

// replaces tabs in the input with the proper number of blanks to space
// to the next tab stop. Assume a fixed set of tab stops, say every n columns
int main() {
  int len = 0;            // current line length
  char line[MAXLINE];     // current input line

  while ((len = consumeLine(line, MAXLINE)) > 0) {
    int columnCount = 0;
    for (int i = 0; i < len; i++) {
      if (line[i] == '\t') {
        int tabOffset = columnCount % TAB_LEN;

        for (int j = 0; j < TAB_LEN - tabOffset; j++) {
          putchar(' ');
          columnCount++;
        }
      } else {
        putchar(line[i]);
        columnCount++;
      }
    }
  }
  return 0;
}