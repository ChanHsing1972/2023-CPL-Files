#include <stdio.h>

int main()
{
  int m, n;
  char a[2005] = {'\0'}, b[2005] = {'\0'};
  scanf("%d %d\n", &m, &n);
  for (int i = 0; i <= 2004; i++)
  {
    a[i] = '0';
    b[i] = '0';
  }
  for (int i = 1; i <= n; i++)
    scanf("%c", &a[i]);

  for (int j = 1; j <= m - 1; j++)
  {
    for (int i = 0; i <= n + 1; i++)
    {
      if (a[i] == '1' && a[i + 1] == '1' && a[i + 2] == '1')
        b[i + 1] = '0';
      else if (a[i] == '1' && a[i + 1] == '1' && a[i + 2] == '0')
        b[i + 1] = '1';
      else if (a[i] == '1' && a[i + 1] == '0' && a[i + 2] == '1')
        b[i + 1] = '1';
      else if (a[i] == '1' && a[i + 1] == '0' && a[i + 2] == '0')
        b[i + 1] = '0';
      else if (a[i] == '0' && a[i + 1] == '1' && a[i + 2] == '1')
        b[i + 1] = '1';
      else if (a[i] == '0' && a[i + 1] == '1' && a[i + 2] == '0')
        b[i + 1] = '1';
      else if (a[i] == '0' && a[i + 1] == '0' && a[i + 2] == '1')
        b[i + 1] = '1';
      else if (a[i] == '0' && a[i + 1] == '0' && a[i + 2] == '0')
        b[i + 1] = '0';
    }
    for (int i = 0; i <= n + 1; i++)
      a[i] = b[i];
    for (int i = 1; i <= n; i++)
    {
      printf("%c", a[i]);
      if (i == n)
        printf("\n");
    }
  }

  return 0;
}