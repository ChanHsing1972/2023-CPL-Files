#include <stdio.h>
#include <math.h>

char canvas[1025][2049];
int main()
{
  int n, top, limit;
  scanf("%d", &n);
  top = pow(2, n);
  // initialise the smallest unit
  canvas[1][top] = '/';
  canvas[1][top + 1] = '\\';
  canvas[2][top - 1] = '/';
  canvas[2][top] = '_';
  canvas[2][top + 1] = '_';
  canvas[2][top + 2] = '\\';

  // copy to the lower left & right corner
  for (int i = 1; i <= n; i++)
  {
    limit = pow(2, i);
    for (int row = 1; row <= limit; row++)
    {
      for (int col = top - limit + 1; col <= top + limit; col++)
      {
        canvas[limit + row][col - limit] = canvas[row][col];
        canvas[limit + row][col + limit] = canvas[row][col];
      }
    }
  }

  // print the pattern
  for (int i = 1; i <= pow(2, n); i++)
  {
    for (int j = 1; j <= pow(2, n + 1); j++)
    {
      if (canvas[i][j] == '/' || canvas[i][j] == '\\' || canvas[i][j] == '_')
        printf("%c", canvas[i][j]);
      else if (j > top + i)
        break;
      else
        printf(" ");
    }
    printf("\n");
  }

  return 0;
}
