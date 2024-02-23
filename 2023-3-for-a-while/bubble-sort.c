#include <stdio.h>

int main()
{
  int t, n, a[1000000] = {0};
  scanf("%d", &t);
  for (int i = 1; i <= t; i++)
  {
    scanf("%d", &n);
    for (int j = 1; j <= n; j++)
    {
      scanf("%d", &a[j]);
    }
    for (int m = 1; m <= n; m++)
    {
      if (a[n] >= a[m] && m == n)
      {
        printf("Yes\n");
      }
      else if (a[n] < a[m])
      {
        printf("No\n");
        break;
      }
    }
  }

  return 0;
}
