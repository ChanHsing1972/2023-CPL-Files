#include <stdio.h>

int main()
{
  int row, col, time = 0;
  char table[301][301] = {'\0'};
  scanf("%d%d", &row, &col);
  getchar();
  for (int i = 1; i <= row; i++)
  {
    for (int j = 1; j <= col; j++)
      scanf("%c", &table[i][j]);
    getchar();
  }

  for (int i = 1; i <= row; i++)
  {
  begin:
    for (int j = 1; j <= col; j++)
    {
      if (table[i][j] != '.') // 该单元格有箭头
      {
        for (int k = 1; table[i + k][j] != '\0'; k++)
          if ((table[i + k][j] == '.' || table[i + k][j] == '\0') && (table[i - k][j] == '.' || table[i - k][j] == '\0') && (table[i][j + k] == '.' || table[i][j + k] == '\0') && (table[i][j - k] == '.' || table[i][j - k] == '\0'))
          {
            printf("-1");
            return 0;
          }
        for (int k = 1; table[i + k][j] != '\0'; k++)
          if (table[i + k][j] != '.' && table[i + k][j] != '\0' && table[i][j] != 'D')
          {
            table[i][j] = 'D';
            time++;
            goto begin;
          }
        for (int k = 1; table[i + k][j] != '\0'; k++)
          if (table[i - k][j] != '.' && table[i - k][j] != '\0' && table[i][j] != 'U')
          {
            table[i][j] = 'U';
            time++;
            goto begin;
          }
        for (int k = 1; table[i + k][j] != '\0'; k++)
          if (table[i][j + k] != '.' && table[i][j + k] != '\0' && table[i][j] != 'R')
          {
            table[i][j] = 'R';
            time++;
            goto begin;
          }
        for (int k = 1; table[i + k][j] != '\0'; k++)
          if (table[i][j - k] != '.' && table[i][j - k] != '\0' && table[i][j] != 'L')
          {
            table[i][j] = 'L';
            time++;
            goto begin;
          }
      }
      if (i == row && j == col)
      {
        printf("%d", time);
        return 0;
      }
    }
  }
  return 0;
}