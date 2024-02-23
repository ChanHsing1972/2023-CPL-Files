#include <stdio.h>
#define M 10007

int main()
{
  int n, i, t, sum = 0;
  long long pro;
  scanf("%d", &n);
  if (n >= 1 && n <= 25)
  {
    for (i = 1; i <= n; i++)
    {
      pro = 1;
      for (t = 1; t <= i; t++)
      {
        pro = pro * t;
        pro = pro % M;
      }
      sum = sum + (pro % M);
    }
    printf("%d", sum % M);
  }

  return 0;
}
