#include <stdio.h>
#include <math.h>

int main()
{
  double pi1 = (log(pow(640320, 3) + 744.0)) / (sqrt(163.0));
  double pi2 = (4 * (atan(1.0 / 5.0)) - atan(1.0 / 239.0)) * 4;
  printf("%.15lf\n%.15lf", pi1, pi2);

  return 0;
}