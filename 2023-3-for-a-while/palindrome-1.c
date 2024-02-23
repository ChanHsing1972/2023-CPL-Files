#include <stdio.h>

int main()
{
  int n;
  char a[2010] = {0};
  scanf("%d\n", &n);
  if (n > 0 && n <= 2000)
  {
    for (int i = 1; i <= n; i++)
    {
      scanf("%c", &a[i]);
    }
    for (int i = 1; i <= n / 2; i++)
    {
      if (a[i] == '?' && a[n - i + 1] == '?')
        return 0;
    }
    for (int i = 1; i <= n; i++)
    {
      if (a[i] == '?')
        a[i] = a[n - i + 1];
    }
    for (int i = 1; i <= n; i++)
    {
      printf("%c", a[i]);
    }
  }

  return 0;
}