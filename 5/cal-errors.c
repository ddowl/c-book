/*
  There is no error checking in day_of_year or month_day. Remedy this defect.
*/

#include <stdio.h>

static char daytab[2][13] = {
  {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
  {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
};

int is_leap_year(int year) {
  return ((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0);
}

int max_days(int is_leap_year) {
  return is_leap_year ? 366 : 365;
}

// set day of year from month & day
int day_of_year(int year, int month, int day) {
  int leap = is_leap_year(year);
  if (month < 0 || month > 12 || day < 0 || day > daytab[leap][month]) {
    return -1;
  }
  for (int i = 1; i < month; i++) {
    day += daytab[leap][i];
  }
  return day;
}

// set month, day from day of year
void month_day(int year, int yearday, int *pmonth, int *pday) {
  int leap = is_leap_year(year);
  if (yearday > max_days(leap) || yearday < 0) {
    *pmonth = -1;
    *pday = -1;
    return;
  }
  int i;
  for (i = 1; yearday > daytab[leap][i]; i++) {
    yearday -= daytab[leap][i];
  }
  *pmonth = i;
  *pday = yearday;
}

int main() {
  printf("%d\n", day_of_year(1995, 05, 03));
  printf("%d\n", day_of_year(1996, 06, 20));
  printf("%d\n", day_of_year(1996, -1, 20));
  printf("%d\n", day_of_year(1996, 13, 03));
  printf("%d\n", day_of_year(1996, 05, -1));
  printf("%d\n", day_of_year(1996, 05, 40));
  printf("\n");

  int month;
  int day;
  month_day(1995, 123, &month, &day);
  printf("%d %d\n", month, day);
  month_day(1995, 365, &month, &day);
  printf("%d %d\n", month, day);
  month_day(1995, 366, &month, &day);
  printf("%d %d\n", month, day);
  month_day(2016, 366, &month, &day);
  printf("%d %d\n", month, day);
  month_day(2016, 367, &month, &day);
  printf("%d %d\n", month, day);
}