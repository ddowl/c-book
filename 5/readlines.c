/*
  Rewrite readlines to store lines in an array supplied by main, rather than
  calling alloc to maintain storage. How much faster is the program?
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXLEN 1000
#define MAXLINES 5000

// getLine: get line into s, return length
int getLine(char s[], int lim) {
  int c, i;

  i = 0;
  while (--lim > 0 && (c = getchar()) != EOF && c != '\n') {
    s[i++] = c;
  }

  if (c == '\n') {
    s[i++] = c;
  }

  s[i] = '\0';
  return i;
}

// read input lines
int readlines(char *lineptr[], int maxlines) {
  int len, nlines;
  char *p, line[MAXLEN];

  nlines = 0;
  while ((len = getLine(line, MAXLEN)) > 0) {
    if (nlines >= maxlines || (p = malloc(len)) == NULL) {
      return -1;
    } else {
      line[len - 1] = '\0'; // delete newline
      strcpy(p, line);
      lineptr[nlines++] = p;
    }
  }
  return nlines;
}

int readlines_no_alloc(char lines[][MAXLEN], int maxlines) {
  int len, nlines;

  nlines = 0;
  while ((len = getLine(lines[nlines], MAXLEN)) > 0)
    if (nlines >= maxlines)                         
      return -1;           
    else
      lines[nlines++][len - 1] = '\0';  /* delete the newline */
  return nlines;
}

int main(int argc, char *argv[]) {
  char *lineptr[MAXLINES];
  char lines[MAXLINES][MAXLEN];

  /* read things into cache, to be fair. */
  readlines_no_alloc(lines, MAXLINES);

  if (argc > 1 && *argv[1] == '2') {
    puts("readlines_no_alloc()");           
    readlines_no_alloc(lines, MAXLINES);
  } else {
    puts("readlines()");
    readlines(lineptr, MAXLINES);
  }
   
  return 0;
}