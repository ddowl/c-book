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

int isInlineComment(char s[], int start) {
  return s[start] == '/' && s[start + 1] == '/';
}

int isMultilineCommentStart(char s[], int start) {
  return s[start] == '/' && s[start + 1] == '*';
}

int isMultilineCommentEnd(char s[], int start) {
  return s[start] == '*' && s[start + 1] == '/';
}

// removes all comments from a C program.
// Don't forget to handle quoted strings and character constants properly.
int main() {
  int len = 0;            // current line length
  char line[MAXLINE];     // current input line

  int inComment = 0;
  while ((len = consumeLine(line, MAXLINE)) > 0) {
    for (int i = 0; i < len; i++) {
      if (isInlineComment(line, i)) {
        printf("\n");
        break; // leave for loop, finish processing this line
      }

      if (!inComment) {
        if (isMultilineCommentStart(line, /* clever hidden comment */ i)) {
          inComment = 1;
          i += 1; // so we'll start looking for the multiline comment end after the /*
          continue;
        }
        putchar(line[i]);
      } else {
        if (isMultilineCommentEnd(line, i)) {
          inComment = 0;
          i += 1;
        }
      }
    }
  }
  return 0;
}