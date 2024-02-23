#include <stdio.h>
#include <stdbool.h>
#define LEN 100
int main()
{
  int n, square[LEN][LEN] = {0}, row, col, count = 2, OldRow, OldCol;
  bool judge[LEN][LEN] = {false};
  scanf("%d", &n);
  square[1][(n + 1) / 2] = 1;
  judge[1][(n + 1) / 2] = true;
  row = 1;
  col = (n + 1) / 2;

  for (;;)
  {
    OldRow = row;
    OldCol = col;
    row--;
    col++;
    if (row == 0)
      row = n;
    if (col == n + 1)
      col = 1;
    if (judge[row][col] == false)
    {
      square[row][col] = count;
      count++;
    }
    else if (judge[row][col] == true)
    {
      if (OldRow + 1 == n + 1)
        OldRow = 0;
      square[OldRow + 1][OldCol] = count;
      count++;
      judge[OldRow + 1][OldCol] = true;
      row = OldRow + 1;
      col = OldCol;
    }

    if (count == n * n + 1)
      break;
  }

  for (int i = 1; i <= n; i++)
  {
    for (int j = 1; j <= n; j++)
      printf("%d ", square[i][j]);
    printf("\n");
  }

  return 0;
}
