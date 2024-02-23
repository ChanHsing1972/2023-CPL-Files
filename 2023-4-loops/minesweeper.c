#include <stdio.h>

int main()
{
  int n, count;
  char a[105][105] = {'\0'};
  scanf("%d\n", &n);
  for (int i = 1; i <= n; i++)
  {
    for (int j = 1; j <= n; j++)
      scanf("%c", &a[i][j]);
    scanf("\n");
  }

  for (int i = 1; i <= n; i++)
  {
    for (int j = 1; j <= n; j++)
    {
      count = 0;
      if (a[i][j] == 'o')
      {
        if (a[i + 1][j] == '*')
          count++;
        if (a[i][j + 1] == '*')
          count++;
        if (a[i - 1][j] == '*')
          count++;
        if (a[i][j - 1] == '*')
          count++;
        if (a[i + 1][j + 1] == '*')
          count++;
        if (a[i + 1][j - 1] == '*')
          count++;
        if (a[i - 1][j + 1] == '*')
          count++;
        if (a[i - 1][j - 1] == '*')
          count++;

        if (count == 0)
          a[i][j] = '0';
        else if (count == 1)
          a[i][j] = '1';
        else if (count == 2)
          a[i][j] = '2';
        else if (count == 3)
          a[i][j] = '3';
        else if (count == 4)
          a[i][j] = '4';
        else if (count == 5)
          a[i][j] = '5';
        else if (count == 6)
          a[i][j] = '6';
        else if (count == 7)
          a[i][j] = '7';
        else if (count == 8)
          a[i][j] = '8';
      }
    }
  }

  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++)
    {
      printf("%c", a[i][j]);
      if (j == n)
        printf("\n");
    }

  return 0;
}