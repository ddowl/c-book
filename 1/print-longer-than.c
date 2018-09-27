#include <stdio.h>

#define MAXLINE 1000
#define CUTOFF_LEN 80

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

// copy 'from' into 'to'; assume to is big enough
void copy(char from[], char to[]) {
  int i = 0;
  while ((to[i] = from[i]) != '\0') { ++i; }
}

// print longest input line
int main() {
  int len = 0;            // current line length
  char line[MAXLINE];     // current input line

  while ((len = consumeLine(line, MAXLINE)) > 0) {
    if (len > CUTOFF_LEN) {
      printf("%s\n", line);
    }
  }
  return 0;
}