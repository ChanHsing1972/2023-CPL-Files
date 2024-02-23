#include <stdio.h>
int main()
{
  int x;
  scanf("%x", &x);
  float *y = &x;
  printf("%d\n%u\n%.6f\n%.3e\n", x, x, *y, *y);
  return 0;
}