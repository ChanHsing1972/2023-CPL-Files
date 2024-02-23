#define _CRT_SECURE_NO_WARNINGS 1
#define INT_MAX 2147483647
#include <stdio.h>
#include <math.h>
#include <string.h>

int main()
{
  int n, len, sum[10010] = {0};
  char a[20] = {0};
  scanf("%d\n", &n);
  for (int i = 0; i < n; i++)
  {
    scanf("%s", a);
    len = strlen(a);

    for (int j = 0; j < len; j++)
    {
      if (a[j] == '1')
      {
        sum[i] += pow(3, len - 1 - j);
      }
      else if (a[j] == '0')
      {
        sum[i] += 0;
      }
      else if (a[j] == 'Z')
      {
        sum[i] -= pow(3, len - 1 - j);
      }
      else if (a[j] != '0' && a[j] != '1' && a[j] != 'Z')
      {
        sum[i] = INT_MAX;
        break;
      }
    }
  }

  for (int t = 0; t < n; t++)
  {
    if (sum[t] != INT_MAX)
      printf("%d\n", sum[t]);
    else if (sum[t] == INT_MAX)
      printf("Radix Error\n");
  }

  return 0;
}