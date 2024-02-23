#include <stdio.h>

int main()
{
  int n, max, i;
  scanf("%d", &n);
  max = n;
  if (n > 0 && n <= 2147483647)
  {
    for (i = 0;; i++)
    {
      if (n == 1)
        break;
      if (n % 2 == 0)
      {
        n = n / 2;
        if (n > max)
          max = n;
      }
      else
      {
        n = 3 * n + 1;
        if (n > max)
          max = n;
      }
    }
    printf("%d %d", i, max);
    return 0;
  }
}