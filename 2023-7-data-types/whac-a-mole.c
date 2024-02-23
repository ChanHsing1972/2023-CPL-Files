#include <stdio.h>

int value[705][705] = {0}, tempValue[605][605] = {0};
int main()
{
  int n, m, d;
  scanf("%d%d%d", &n, &m, &d);
  for (int i = d; i <= d + n - 1; i++)
    for (int j = d; j <= d + m - 1; j++)
      scanf("%d", &value[i][j]);

  int x = d, y = d, oldX, oldY;
  for (int i = x - d; i <= x + d; i++) // initialise "tempValue"
    for (int j = y - d; j <= y + d; j++)
      if ((i - x >= 0 && j - y >= 0 && i - x + j - y <= d) || (i - x >= 0 && j - y <= 0 && i - x + y - j <= d) || (i - x <= 0 && j - y >= 0 && x - i + j - y <= d) || (i - x <= 0 && j - y <= 0 && x - i + y - j <= d))
        tempValue[x - d + 1][y - d + 1] += value[i][j];
  oldX = x;
  oldY = y;
  y++;
  for (;;)
  {
    if (y == d) // if the center is on the left edge, down-move the center, and only calculate values around the hammer
    {
      tempValue[x - d + 1][1] = tempValue[x - d][1];
      for (int m = 0; m <= d; m++)
      {
        tempValue[x - d + 1][y - d + 1] += value[x + d - m][y + m];
        tempValue[x - d + 1][y - d + 1] -= value[x - d - 1 + m][y + m];
      }
    }
    else // else, right-move the center, and only calculate values around the hammer
    {
      tempValue[x - d + 1][y - d + 1] = tempValue[oldX - d + 1][oldY - d + 1];
      for (int m = 0; m <= d; m++)
      {
        tempValue[x - d + 1][y - d + 1] += value[x + d - m][y + m] + value[x - d + m][y + m];
        tempValue[x - d + 1][y - d + 1] -= value[x + d - m][y - m - 1] + value[x - d + m][y - m - 1];
      }
      tempValue[x - d + 1][y - d + 1] += value[x][y - d - 1];
      tempValue[x - d + 1][y - d + 1] -= value[x][y + d];
    }
    oldX = x;
    oldY = y;
    if (y == d + m - 1 && x < d + n - 1) // if the center is on the right edge but not the end, move it to the beginning of the next row
    {
      x++;
      y = d;
    }
    else if (y == d + m - 1 && x == d + n - 1) // if end, quit
      break;
    else // else, right-move the center
      y++;
  }

  int maxValue = tempValue[1][1], count = 0;
  for (int i = 1; i <= n; i++) // find the max, how many times it appears and the coodinates
    for (int j = 1; j <= m; j++)
    {
      if (tempValue[i][j] > maxValue)
      {
        count = 1;
        maxValue = tempValue[i][j];
      }
      else if (tempValue[i][j] == maxValue)
        count++;
    }
  printf("%d %d\n", maxValue, count);
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++)
      if (tempValue[i][j] == maxValue)
        printf("%d %d\n", i, j);
  return 0;
}