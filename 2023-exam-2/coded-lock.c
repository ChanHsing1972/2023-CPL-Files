#include <stdio.h>

int main()
{
  int w, n, d, code[10100] = {0}, ans[10100] = {0}, k1, k2, time = 0, sum = 0;
  scanf("%d%d%d", &w, &n, &d);
  for (int i = 1; i <= w; i++)
    scanf("%d", &code[i]);

  for (int i = 1; i <= w / 2; i++)
  {
    int temp = code[i];
    for (;;)
    {
      // +
      if (temp > n)
      {
        temp = temp % n;
        time++;
      }
      if (temp == code[w + 1 - i])
        break;
      if (time == 1000000)
      {
        printf("Impossible");
        return 0;
      }
      temp = temp + d;
      k1++;
      if (temp == code[w + 1 - i])
        break;
    }
    time = 0;
    temp = code[i];

    for (;;)
    {
      // -
      if (temp <= 0)
      {
        temp = temp + n;
        time++;
      }
      if (temp == code[w + 1 - i])
        break;
      if (time == 1000000)
      {
        printf("Impossible");
        return 0;
      }
      temp = temp - d;
      k2++;
      if (temp == code[w + 1 - i])
        break;
    }

    if (k1 < k2)
      ans[i] = k1;
    else
      ans[i] = k2;

    k1 = 0;
    k2 = 0;
    time = 0;
  }

  for (int i = 1; i <= 1009; i++)
    sum = sum + ans[i];
  printf("%d", sum);
  return 0;
}