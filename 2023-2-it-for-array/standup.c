#include <stdio.h>

int main()
{
  int n, a[100000] = {0}, i, tuo = 0, left = 0;
  scanf("%d", &n);
  if (n >= 0 && n <= 100000)
  {
    for (i = 0; i <= n; i++)
    {
      scanf("%d", &a[i]);
    }
    for (i = 1; i <= n; i++)
    {
      left = left + a[i - 1];
      if (a[i] != 0 && left < i)
      {
        tuo = tuo + i - left;
        left = left + i - left;
      }
    }
    printf("%d", tuo);

    return 0;
  }
}