#include <stdio.h>

int main()
{
  int n, a[1000005] = {0}, i, num;
  scanf("%d", &n);
  if (n >= 1 && n <= 100000)
  {
    for (i = 1; i <= 2 * n - 1; i++)
    {
      scanf("%d", &num);
      if (num >= 1 && num <= (10 * n))
        a[num]++;
    }
    for (i = 1; i <= 1000005; i++)
    {
      if (a[i] == 1)
        printf("%d", i);
    }
  }

  return 0;
}
