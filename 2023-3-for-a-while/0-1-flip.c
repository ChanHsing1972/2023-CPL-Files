#include <stdio.h>

int main()
{
  int n, a[2010] = {0}, i, j;
  scanf("%d", &n);
  for (j = 1; j <= n; j++)
  {
    for (i = 1; i <= n; i++)
    {
      if (i % j == 0)
      {
        if (a[i] == 0)
          a[i] = 1;
        else
          a[i] = 0;
      }
    }
  }

  for (i = 1; i <= n; i++)
  {
    if (a[i] == 1)
      printf("%d ", i);
  }

  return 0;
}