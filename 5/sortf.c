/*
  Add the option -f to fold upper and lower case together, so that case
  distinctions are not made during sorting; for example, a and A compare
  equal.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>

#define MAXLINES 5000   // max # lines to be sorted
#define MAXLEN 1000

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

void writelines(char *lineptr[], int nlines) {
  while (nlines-- > 0) {
    printf("%s\n", *lineptr++);
  }
}

void swap(void *v[], int i, int j) {
  void *temp;

  temp = v[i];
  v[i] = v[j];
  v[j] = temp;
}

// compare s1 and s2 numerically
int numcmp(char *s1, char *s2) {
  double v1, v2;

  v1 = atof(s1);
  v2 = atof(s2);
  return v1 - v2;
}

// sort v[left]...v[right] into increasing order
void qsort_custom(void *v[], int left, int right, int (*comp)(void *, void *), int reverse) {
  if (left >= right) { return; }

  // set pivot
  swap(v, left, (left + right) / 2);

  // partition
  int last = left;
  for (int i = left + 1; i <= right; i++) {
    int cmp = (*comp)(v[i], v[left]);
    if (reverse ? cmp > 0 : cmp < 0) {
      swap(v, ++last, i);
    }
  }
  swap(v, left, last);

  // recurse on sub-partitions
  qsort_custom(v, left, last - 1, comp, reverse);
  qsort_custom(v, last + 1, right, comp, reverse);
}

int main(int argc, char *argv[]) {
  int nlines;         // number of input lines read
  int numeric = 0;    // 1 if numeric sort
  int reverse = 0;    // 1 if reverse sort
  int ignore_case = 0; // 1 if sort ignores case sensitivity

  char *lineptr[MAXLINES];

  int c;
  while (--argc > 0 && (*++argv)[0] == '-') {
    while ((c = *++argv[0])) {
      switch (c) {
        case 'n':
          numeric = 1;
          break;
        case 'r':
          reverse = 1;
          break;
        case 'f':
          ignore_case = 1;
          break;
        default:
          printf("sort: illegal option %c\n", c);
          exit(1);
      }
    }
  }

  if ((nlines = readlines(lineptr, MAXLINES)) >= 0) {
    int (*comparator)(void*, void*);  // define comparator function ptr
    if (numeric) {
      comparator = (void *) numcmp;
    } else if (ignore_case) {
      comparator = (void *) strcasecmp;
    } else {
      comparator = (void *) strcmp;
    }

    qsort_custom((void **) lineptr, 0, nlines - 1, comparator, reverse);
    writelines(lineptr, nlines);
    return 0;
  } else {
    printf("input too big to sort\n");
    return 1;
  }
}