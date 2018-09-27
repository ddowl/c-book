#include <stdio.h>

int main() {
  float fahr, celsius;
  int lower, upper, step;

  lower = 0;
  upper = 300;
  step = 20;

  // Fahrenheit to Celsius
  printf("Fahrenheit\tCelsius\n");
  fahr = lower;
  while (fahr <= upper) {
    celsius = (5.0 / 9.0) * (fahr - 32.0);
    printf("%3.0f\t\t\t\t%6.1f\n", fahr, celsius);
    fahr = fahr + step;
  }

  // Celsius to Fahrenheit
  printf("Celsius\tFahrenheit\n");
  celsius = lower;
  while (celsius <= upper) {
    fahr = (celsius / (5.0 / 9.0)) + 32.0;
    printf("%3.0f\t\t\t\t%6.1f\n", celsius, fahr);
    celsius = celsius + step;
  }

  // Fahrenheit to Celsius in reverse with for loop
  printf("Fahrenheit\tCelsius\n");
  for (fahr = 300; fahr >= 0; fahr = fahr - 20) {
    printf("%3.0f %6.1f\n", fahr, (5.0 / 9.0) * (fahr - 32.0));
  }
}