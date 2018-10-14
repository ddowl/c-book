/*
  Write the program tail, which prints the last n line of its input. By default,
  n is 10, let us say, but it can be changed by an optional argument, so that

    tail -n

  prints the last n lines. The program should behave rationally no matter how
  unreasonable the input or the value of n. Write the program so it makes the
  best use of available storage; lines should be stored as in the sorting
  program of Section 5.6, not in a two-dimensional array of fixed size.
*/

/*
  3 strategies:

  1) Memory-intensive: Load all of input into memory, then print out last N lines.

  2) Keep N lines: Hold at most N lines of input in memory. When a new line comes in
  above N, copy each line back 1 slot to make space. Least recent line of input is
  forgotten.

  3) Keen N lines (round-robin): like 2) but instead of copying lines, overwrite least
  recent line with new line, and keep track of new start. Ex. start := 4, last line @ 3
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXLINE 1000
#define DEFAULT_TAIL_LINES 10

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

/* duplicates a string */
char *dupstr(const char *s) {
  char *p = malloc(strlen(s) + 1); 
  if (p) { strcpy(p, s); }
  return p;
}

int inc_curr_line(int line_idx, int num_lines) {
  return (line_idx + 1) % num_lines;
}

int main(int argc, char *argv[]) {
  int n = DEFAULT_TAIL_LINES;
  if (argc > 1 && strcmp(argv[1], "-n") == 0) {
    n = atoi(argv[2]);
  }

  /* First, let's get enough storage for a list of n pointers... */
  char **line_ptrs = malloc(sizeof *line_ptrs * n);
  if (!line_ptrs) {
    fprintf(stderr, "Out of memory.  Sorry.\n");
    return EXIT_FAILURE;
  }
  /* and make them all point to NULL */
  for (int i = 0; i < n; i++) {
    line_ptrs[i] = NULL;
  }

  /* read input! */
  int len;
  char buf[MAXLINE];
  int curr_line = 0;
  while ((len = getLine(buf, sizeof buf)) > 0) {
    // printf("%d %s\n", len, buf);
    if (line_ptrs[curr_line]) {
      // we have to make space for the new line
      free(line_ptrs[curr_line]);
    }
    line_ptrs[curr_line] = dupstr(buf);
    curr_line = inc_curr_line(curr_line, n);
  }

  /* finished reading input, so print the lines */
  for (int i = 0; i < n; i++) {
    int j = (curr_line + i) % n;
    if (line_ptrs[j]) {
      printf("%s", line_ptrs[j]);
      free(line_ptrs[j]);
    }
  }
}