/*
  Our binary search makes two tests inside the loop, when one
  would suffice (at the price of more tests outside). Write a version
  with only one test inside the loop and measure the difference in run-time.
*/

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

}

int main() {

}