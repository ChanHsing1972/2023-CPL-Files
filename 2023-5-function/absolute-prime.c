#include <stdio.h>
#include <stdbool.h>
#include <math.h>

int IsPrime(int num);
int reverse(int t);

int main()
{
  int n, count = 0;
  scanf("%d", &n);

  for (int i = 2; i <= n; i++)
  {
    int i1 = reverse(i);
    if ((IsPrime(i) == true) && (IsPrime(i1) == true))
      count++;
  }
  printf("%d", count);

  return 0;
}

int IsPrime(int num)
{
  int flag = true;
  for (int i = 2; i <= sqrt(num + 0.5); i++)
  {
    if (num % i == 0)
    {
      flag = false;
      break;
    }
  }
  if (flag == true)
    return true;
  else
    return false;
}

int reverse(int t)
{
  int reverse = 0, remain;
  for (;;)
  {
    if (t > 0)
    {
      remain = t % 10;
      reverse = reverse * 10 + remain;
      t = (t - remain) / 10;
    }
    else
      break;
  }
  return reverse;
}