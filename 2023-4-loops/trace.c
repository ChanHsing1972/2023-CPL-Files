#include <stdio.h>
#include <stdbool.h>

int main()
{
  int n, m, x, y, ans = 1, coords[2510][3] = {0}, t = 2;
  char map[55][55] = {'\0'};
  bool flag[55][55] = {false};
  scanf("%d %d %d %d", &n, &m, &x, &y);
  for (int i = 1; i <= n; i++)
  {
    scanf("%s", &map[i][1]);
  }
  coords[1][1] = x;
  coords[1][2] = y;
  flag[x][y] = true;

  for (;;)
  {
    if (x <= 0 || y <= 0)
      break;
    if (map[x + 1][y] == '#' && flag[x + 1][y] == false)
    {
      ans++;
      flag[x + 1][y] = true;
      x = x + 1;
      coords[t][1] = x;
      coords[t][2] = y;
      t++;
    }
    else if (map[x][y + 1] == '#' && flag[x][y + 1] == false)
    {
      ans++;
      flag[x][y + 1] = true;
      y = y + 1;
      coords[t][1] = x;
      coords[t][2] = y;
      t++;
    }
    else if (map[x - 1][y] == '#' && flag[x - 1][y] == false)
    {
      ans++;
      flag[x - 1][y] = true;
      x = x - 1;
      coords[t][1] = x;
      coords[t][2] = y;
      t++;
    }
    else if (map[x][y - 1] == '#' && flag[x][y - 1] == false)
    {
      ans++;
      flag[x][y - 1] = true;
      y = y - 1;
      coords[t][1] = x;
      coords[t][2] = y;
      t++;
    }
    else
      break;
  }

  printf("%d\n", ans);
  for (int i = 1; i <= ans; i++)
  {
    for (int j = 1; j <= 2; j++)
      printf("%d ", coords[i][j]);
    printf("\n");
  }

  return 0;
}
