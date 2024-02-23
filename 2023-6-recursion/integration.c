#include <stdio.h>
#include <math.h>

double integration(double l, double r, double E, double last);
double Simpson(double a, double b);
double f(double x);

double a, b, E = 0.0001;
int arr[25], n, p;
int main()
{
  scanf("%d%d", &n, &p);
  for (int i = 1; i <= n + 1; i++)
    scanf("%d", &arr[i]);
  scanf("%lf%lf", &a, &b);
  printf("%lf", integration(a, b, E, Simpson(a, b)));
  return 0;
}

double integration(double l, double r, double E, double last)
{
  double mid = (l + r) / 2, SL, SR;
  SL = Simpson(l, mid);
  SR = Simpson(mid, r);
  if (fabs(SL + SR - last) <= 15 * E)
    return SL + SR + (SL + SR - last) / 15;
  return integration(l, mid, E / 2, SL) + integration(mid, r, E / 2, SR);
}

double Simpson(double a, double b)
{
  return (4 * f((a + b) / 2) + f(a) + f(b)) / 6 * (b - a);
}

double f(double x)
{
  double result = 0, power = 1;
  for (int i = 1; i <= n + 1; i++)
  {
    result += arr[i] * power;
    power *= x;
  }
  if (p == 2)
    result = result * result;
  else if (p == -2)
    result = 1 / (result * result);
  else if (p == 1)
    ;
  else if (p == -1)
    result = 1 / result;

  return result;
}