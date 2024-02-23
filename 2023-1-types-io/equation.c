#include <stdio.h>
#include <math.h>

int main()
{
  double x1, m1, m2, delta;
  int p, q;
  scanf("%d %d", &p, &q);
  delta = (q / 2.0) * (q / 2.0) + (p / 3.0) * (p / 3.0) * (p / 3.0);
  if ((delta >= 0))
  {
    if (-(q / 2.0) + sqrt(delta) > 0)
    {
      m1 = pow(-(q / 2.0) + sqrt(delta), 1.0 / 3.0);
    }
    else if (-(q / 2.0) + sqrt(delta) < 0)
    {
      m1 = -pow((q / 2.0) - sqrt(delta), 1.0 / 3.0);
    }
    else
    {
      m1 = 0;
    }
    if (-(q / 2.0) - sqrt(delta) > 0)
    {
      m2 = pow(-(q / 2.0) - sqrt(delta), 1.0 / 3.0);
    }
    else if (-(q / 2.0) - sqrt(delta) < 0)
    {
      m2 = -pow((q / 2.0) + sqrt(delta), 1.0 / 3.0);
    }
    else
    {
      m2 = 0;
    }
    x1 = m1 + m2;
    printf("%.3lf", x1);
  }
  else
    printf("error");

  return 0;
}
