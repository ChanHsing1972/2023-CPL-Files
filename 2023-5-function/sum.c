#include <stdio.h>

int main()
{
  int n, t, sum = 0, temp;
  scanf("%d %d", &n, &t);
  temp = t;
  for (int i = 1; i <= n; i++)
  {
    sum = sum + temp;
    temp = temp * 10 + t;
  }
  printf("%d", sum);

  return 0;
}
