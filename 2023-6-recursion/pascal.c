#include <stdio.h>

int pascal(int a, int b);

int main()
{
  int a, b;
  scanf("%d%d", &a, &b);
  printf("%d", pascal(a, b));
  return 0;
}

int pascal(int a, int b)
{
  if (b == 1 || a == b)
  {
    return 1;
  }
  else
  {
    return pascal(a - 1, b - 1) + pascal(a - 1, b);
  }
}