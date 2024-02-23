#include <stdio.h>

int main()
{
  int year, month, day, a, y, m, jdn;
  scanf("%d %d %d", &year, &month, &day);
  if ((year >= 1900 && month >= 1 && day >= 1) && (year <= 2599 && month <= 12 && day <= 31))
  {
    a = (14 - month) / 12;
    y = year + 4800 - a;
    m = month + 12 * a - 3;
    jdn = day + (153 * m + 2) / 5 + 365 * y + y / 4 - y / 100 + y / 400 - 32045;
    printf("%d", jdn);
  }
  else
    printf("error");

  return 0;
}