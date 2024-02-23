#include <stdio.h>

int main()
{
  int day, year, hour, minute, second;
  char month[20] = {0}, weekday[20] = {0};
  for (int i = 0; i < 20; i++)
  {
    scanf("%c", &month[i]);
    if (month[i] == ' ')
      break;
  }
  scanf("%d %d ", &day, &year);
  if (year >= 0 && year <= 9999)
  {
    for (int i = 0; i < 20; i++)
    {
      scanf("%c", &weekday[i]);
      if (weekday[i] == ' ')
        break;
    }
    scanf("%d %d %d", &hour, &minute, &second);

    printf("%c%c%c ", weekday[0], weekday[1], weekday[2]);
    printf("%c%c%c ", month[0], month[1], month[2]);
    printf("%.2d %.2d:%.2d:%.2d %.4d", day, hour, minute, second, year);
  }
  else
    printf("error");

  return 0;
}