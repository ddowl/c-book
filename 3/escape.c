/*
  Write a function escape(s, t) that converts characters like newline
  and tab into visible escape sequences like \n and \t as it copies the
  string t to s. Use a switch. Write a function for the other direction as well,
  converting escape sequences into the real characters.
*/

#include <stdio.h>
#include <string.h>
#define SUFFICIENT_BUFFER_LEN 100

void escape(char src[], char dest[]) {
  int i, j;
  for(i = j = 0; i < strlen(src); i++, j++) {
    if (src[i] == '\n') {
      dest[j] = '\\';
      dest[j+1] = 'n';
      j++;
    } else if (src[i] == '\t') {
      dest[j] = '\\';
      dest[j+1] = 't';
      j++;
    } else {
      dest[j] = src[i];
    }
  }
  dest[j] = '\0';
}

void unescape(char src[], char dest[]) {
  int i, j;
  for(i = j = 0; i < strlen(src); i++, j++) {
    if (src[i] == '\\') {
      if (src[i+1] == 'n') {
        dest[j] = '\n';
        i++;
      } else if (src[i+1] == 't') {
        dest[j] = '\t';
        i++;
      } else {
        dest[j] = src[i]; // unfortunate duplication :(
      }
    } else {
      dest[j] = src[i];
    }
  }
  dest[j] = '\0';
}

int main() {
  char escapes[] = "\n\t\n\n\t";
  char literals[] = "\\n\\t\\n\\n\\t";
  char escapeDest[SUFFICIENT_BUFFER_LEN];
  char literalDest[SUFFICIENT_BUFFER_LEN];

  escape(escapes, escapeDest);
  unescape(literals, literalDest);
  printf("escape(%s) = %s\n", escapes, escapeDest);
  printf("unescape(%s) = %s\n", literals, literalDest);
}