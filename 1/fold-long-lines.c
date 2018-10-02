#include <stdio.h>
#include <string.h>

#define MAXLINE 1000
#define TAB_LEN 8
#define COLUMN_WRAP 10

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

int getColumnsInStr(char s[], int start, int end) {
  int colSize = 0;
  for (int i = start; i < end; i++) {
    if (s[i] == '\t') {
      colSize += TAB_LEN;
    } else {
      colSize++;
    }
  }
  return colSize;
}

int indexOfLastNonBlankChar(char s[], int end) {
  for (int i = end; i >= 0; i--) {
    if (s[i] != ' ' && s[i] != '\t') {
      return i;
    }
  }
  return -1;
}

int indexOfFirstNonBlankChar(char s[], int start, int end) {
  for (int i = start; i < end; i++) {
    if (s[i] != ' ' && s[i] != '\t') {
      return i;
    }
  }
  return end;
}

// folds long input lines into two or more shorter lines after the last
// non-blank character that occurs before the nth column of input.
// Make sure we do something intelligent with _very_ long lines, and if
// there are no blanks or tabs before the specified column.

// NOTE: Still needs work! doesn't handle inputs with tabs very well
// leaving debug prints in for later use
int main() {
  int len = 0;            // current line length
  char line[MAXLINE];     // current input line


  while ((len = consumeLine(line, MAXLINE)) > 0) {
    int currStart = 0;
    int currEnd = COLUMN_WRAP;
    int colSize = getColumnsInStr(line, 0, len);
    int firstNonBlankChar;
    int lastNonBlankChar;

    while (colSize - currStart > COLUMN_WRAP) {
      // the rest of the string is too big, we'll have to wrap it
      currEnd = currStart + COLUMN_WRAP;

      // find the bounds of the non-blank characters we can print
      firstNonBlankChar = indexOfFirstNonBlankChar(line, currStart, currEnd);
      lastNonBlankChar = indexOfLastNonBlankChar(line, currEnd);
      // printf("%d %d %d s%d\n", currStart, currEnd, firstNonBlankChar, lastNonBlankChar);
      printf("%.*s\n", lastNonBlankChar - currStart + 1, line + firstNonBlankChar);
      // printf("%d %d %d %d\n", currStart, currEnd, firstNonBlankChar, lastNonBlankChar);
      currStart = indexOfFirstNonBlankChar(line, currEnd + 1, len);
      // printf("%d\n", currStart);
    }
    
    // print the rest of the string
    // firstNonBlankChar = indexOfFirstNonBlankChar(line, currStart, currEnd);
    // lastNonBlankChar = indexOfLastNonBlankChar(line, currEnd);
    printf("%.*s\n", currStart, line + currStart);
    // printf("%d %d %d %d\n", currStart, currEnd, firstNonBlankChar, lastNonBlankChar);
  }
  return 0;
}