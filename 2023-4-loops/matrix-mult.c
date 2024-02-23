#include <stdio.h>
int main()
{
  int m, n, p, mat_A[105][105] = {0}, mat_B[105][105] = {0}, mat_C[105][105] = {0};
  scanf("%d %d %d", &m, &n, &p);
  for (int i = 1; i <= m; i++)
    for (int j = 1; j <= n; j++)
      scanf("%d", &mat_A[i][j]);
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= p; j++)
      scanf("%d", &mat_B[i][j]);

  for (int i = 1; i <= m; i++)
    for (int t = 1; t <= p; t++)
      for (int j = 1; j <= n; j++)
        mat_C[i][t] += mat_A[i][j] * mat_B[j][t];

  for (int i = 1; i <= m; i++)
    for (int j = 1; j <= p; j++)
    {
      printf("%d ", mat_C[i][j]);
      if (j == p)
        printf("\n");
    }
  return 0;
}