/*
  Extend atof to handle scientific notation of the form

      123.45d-6

  where a floating-point number may be followed by e or E
  and an optionally signed exponent.
*/

#include <ctype.h>
#include <stdio.h>
#include <math.h>

double atof(char s[]) {
  double val, power;
  int i, sign;


  for (i = 0; isspace(s[i]); i++) {} // skip white space

  sign = (s[i] == '-') ? -1 : 1;
  if (s[i] == '+' || s[i] == '-') { i++; }

  for (val = 0.0; isdigit(s[i]); i++) {
    val = 10.0 * val + (s[i] - '0');
  }

  if (s[i] == '.') { i++; }

  for (power = 1.0; isdigit(s[i]); i++) {
    val = 10.0 * val + (s[i] - '0');
    power *= 10.0;
  }

  int expSign = 1;
  int expVal = 1;
  if (s[i] == 'e' || s[i] == 'E') {
    i++;

    if (s[i] == '-') {
      i++;
      expSign = -1;
    }
    for (expVal = 0; isdigit(s[i]); i++) {
      expVal = 10 * expVal + (s[i] - '0');
    }

    if (expSign > 0) {
      val *= pow(10, expVal);
    } else {
      val /= pow(10, expVal);
    }
  }

  return sign * val / power;
}

void printAtof(char s[]) {
  printf("atof(%s) = %f\n", s, atof(s));
}

int main() {
  printAtof("0.0");
  printAtof("1.0");
  printAtof("1.1");
  printAtof("100.01");
  printAtof("1234.1234");
  printAtof("-1.0");
  printAtof("-0.0");
  printAtof("1.0e2");
  printAtof("0.314519e2");
  printAtof("12.7904e-1");
  printAtof("-1.0e4");
  printAtof("1.0e10");
}