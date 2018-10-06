/*
  Our binary search makes two tests inside the loop, when one
  would suffice (at the price of more tests outside). Write a version
  with only one test inside the loop and measure the difference in run-time.
*/

#include <time.h>
#include <stdio.h>

int binsearch(int x, int v[], int n) {
  int low, high, mid;

  low = 0;
  high = n - 1;
  while (low <= high) {
    mid = (low + high) / 2;
    if (x < v[mid]) {
      high = mid - 1;
    } else if (x > v[mid]) {
      low = mid + 1;
    } else { // found match
      return mid;
    }
  }
  return -1;
}

int fastBinsearch(int x, int v[], int n) {
  int low, high, mid;

  low = 0;
  high = n - 1;
  mid = (low+high) / 2;

  while ((low <= high) && (v[mid] != x)) {
    if (x < v[mid]) {
      high = mid - 1;
    } else {
      low = mid + 1;
    }
    mid = (low+high) / 2;
  }
  return (v[mid] == x) ? mid : -1;
}

void measureFunc(int (*func)(int, int[], int), int arr[], int len) {
  // Calculate the time taken by func()
  clock_t t;
  t = clock();
  for (int i = 0; i < len; i++) {
    (*func)(i, arr, len);
  }
  t = clock() - t;
  double time_taken = ((double)t)/CLOCKS_PER_SEC; // in seconds

  printf("func() took %f seconds to execute \n", time_taken);
}


int main() {
  int len = 1000000;
  int arr[len];
  for (int i = 0; i < len; i++) {
    arr[i] = i;
  }

  int x = 1234;
  printf("binsearch(%d) = %d\n", x, binsearch(x, arr, len));
  printf("fastBinsearch(%d) = %d\n", x, fastBinsearch(x, arr, len));

  printf("Timing binsearch...\n");
  measureFunc(binsearch, arr, len);
  printf("Timing fastBinsearch...\n");
  measureFunc(fastBinsearch, arr, len);
}