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

// replaces strings of blanks with the minimum number of tabs and blanks
// to acheive the same spacing.
int main() {
  int len = 0;            // current line length
  char line[MAXLINE];     // current input line

  while ((len = consumeLine(line, MAXLINE)) > 0) {
    // strat: when we find a whitespace, figure out bounds of run in line
    // use difference of upper and lower bounds to determine # tabs
    // (upper - lower) / TAB_LEN = # of tabs
    // (upper - lower) % TAB_LEN = # of whitespaces
    for (int i = 0; i < len; i++) {
      if (line[i] == ' ') {
        int numBlanks = 1;
        while (line[i + numBlanks] == ' ') { numBlanks++; }

        for (int j = 0; j < numBlanks / TAB_LEN; j++) {
          putchar('\t');
        }

        for (int j = 0; j < numBlanks % TAB_LEN; j++) {
          putchar(' ');
        }

        i += numBlanks - 1;
      } else {
        putchar(line[i]);
      }
    }
  }
  return 0;
}