#include <stdio.h>
#include <math.h>

int main()
{
  float x, y, sum = 0;
  int n;
  scanf("%f %d", &x, &n);
  if (x > -1.0 && x <= 1.0 && n >= 1 && n <= 1000)
  {
    for (int i = 0; i <= n; i++)
    {
      if (i % 2 == 0)
      {
        if (x > 0)
          sum = sum + pow(x, 2 * i + 1) / (2.0 * i + 1);
        else if (x < 0)
          sum = sum - pow(-x, 2 * i + 1) / (2.0 * i + 1);
        else
          sum = sum;
      }
      else
      {
        if (x > 0)
          sum = sum - pow(x, 2 * i + 1) / (2.0 * i + 1);
        else if (x < 0)
          sum = sum + pow(-x, 2 * i + 1) / (2.0 * i + 1);
        else
          sum = sum;
      }
    }
    printf("%.10f", sum * 4);
  }

  return 0;
}