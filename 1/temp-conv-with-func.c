#include <stdio.h>

#define LOWER 0
#define UPPER 300
#define STEP 20

float fahrToCels(float fahr) {
  return (5.0 / 9.0) * (fahr - 32.0);
}

int main() {
  printf("Fahrenheit\tCelsius\n");
  for (float fahr = LOWER; fahr <= UPPER; fahr = fahr + STEP) {
    printf("%3.0f\t\t%6.1f\n", fahr, fahrToCels(fahr));
  }
}