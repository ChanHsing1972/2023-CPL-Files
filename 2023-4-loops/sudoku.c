#include <stdio.h>

int main()
{
  int a[15][15] = {0}, count[10] = {0}, tmp;
  for (int i = 1; i <= 9; i++)
    for (int j = 1; j <= 9; j++)
      scanf("%d", &a[i][j]);

  for (int i = 1; i <= 9; i++)
  {
    for (int j = 1; j <= 9; j++)
      count[j] = 0;
    for (int j = 1; j <= 9; j++)
    {
      tmp = a[i][j];
      count[tmp]++;
    }
    for (int j = 1; j <= 9; j++)
    {
      if (count[j] == 1)
        ;
      else if (count[j] != 1)
      {
        printf("NO");
        return 0;
      }
    }
  }

  for (int i = 1; i <= 9; i++)
  {
    for (int j = 1; j <= 9; j++)
      count[j] = 0;
    for (int j = 1; j <= 9; j++)
    {
      tmp = a[j][i];
      count[tmp]++;
    }
    for (int j = 1; j <= 9; j++)
    {
      if (count[j] == 1)
        ;
      else if (count[j] != 1)
      {
        printf("NO");
        return 0;
      }
    }
  }

  for (int i = 1; i <= 7; i = i + 3)
  {
    for (int j = 1; j <= 7; j = j + 3)
    {
      for (int m = 1; m <= 9; m++)
        count[m] = 0;
      for (int m = 0; m <= 2; m++)
      {
        for (int n = 0; n <= 2; n++)
        {
          tmp = a[i + m][j + n];
          count[tmp]++;
        }
      }
      for (int m = 1; m <= 9; m++)
      {
        if (count[m] == 1)
          ;
        else if (count[m] != 1)
        {
          printf("NO");
          return 0;
        }
      }
    }
  }

  printf("YES");

  return 0;
}