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

void reverse(char s[]) {
  int len = strlen(s);
  for (int i = 0; i < len / 2; ++i) {
    char temp = s[i];
    s[i] = s[len - i - 1];
    s[len - i - 1] = temp;
  }
}

// NOTE: currently commented as some itoa functions in the 
// Ch3 exercises rely on the reverse function, but we haven't
// been introduced to header files / im too lazy to link.

// reverses each line of input
// int main() {
//   int len = 0;            // current line length
//   char line[MAXLINE];     // current input line

//   while ((len = consumeLine(line, MAXLINE)) > 0) {
//     reverse(line);
//     printf("%s\n", line);
//   }
//   return 0;
// }