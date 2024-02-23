#define _CRT_SECURE_NO_WARNINGS 1
#define LIVE 0
#define DIE 1
#include <stdio.h>

int main()
{
  int n, k, a[100000] = {LIVE}, num = 0, i, lives;
  scanf("%d %d", &n, &k);
  lives = n;
  for (i = 1; i <= n; i++)
  {
    if (a[i] == LIVE)
    {
      num++;
      if (num == k)
      {
        a[i] = DIE;
        num = 0;
        lives--;
      }
    }

    if (i == n)
      i = 0;
    if (lives == 1)
    {
      for (i = 1; i <= n; i++)
      {
        if (a[i] == LIVE)
          printf("%d", i);
      }
    }
  }

  return 0;
}