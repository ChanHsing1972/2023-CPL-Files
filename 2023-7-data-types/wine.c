#include <stdio.h>

int main()
{
  int n, l, price[10005] = {0}, limit[10005] = {0}, sum = 0, count[1000000] = {0};
  scanf("%d%d", &n, &l);
  for (int i = 1; i <= n; i++)
    scanf("%d", &price[i]);
  for (int i = 1; i <= n; i++)
    scanf("%d", &limit[i]);
  for (int i = 1; i <= n; i++)
    count[price[i]]++;
  for (int i = 1000000; i >= 1; i--)
  {
    if (count[i] != 0)
    {
      for (int j = 1; j <= n; j++)
        if (price[j] == i && limit[j] >= l)
        {
          sum = sum + price[j] * l;
          goto end;
        }
        else if (price[j] == i && limit[j] < l)
        {
          sum = sum + price[j] * limit[j];
          l = l - limit[j];
        }
    }
  }
end:
  printf("%d", sum);

  return 0;
}