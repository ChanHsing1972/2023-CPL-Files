#include <stdio.h>

int pour(int k, int a, int b, int c, int a0, int b0, int c0);
int va, vb, vc, judge;
int main()
{
  int k, a, b, c, a0, b0, c0;
  scanf("%d%d%d%d%d%d%d%d%d%d", &k, &va, &vb, &vc, &a, &b, &c, &a0, &b0, &c0);
  pour(k, a, b, c, a0, b0, c0);
  judge == 1 ? printf("Yes") : printf("No");
  return 0;
}

int pour(int k, int a, int b, int c, int a0, int b0, int c0)
{
  if (k >= 0 && a == a0 && b == b0 && c == c0)
  {
    judge = 1;
    return 0;
  }
  else if (k > 0)
  {
    pour(k - 1, a + b <= va ? a + b : va, 0, c, a0, b0, c0);
    pour(k - 1, 0, a + b <= vb ? b + a : vb, c, a0, b0, c0);
    pour(k - 1, a, b + c <= vb ? b + c : vb, 0, a0, b0, c0);
    pour(k - 1, a, 0, b + c <= vc ? b + c : vc, a0, b0, c0);
    pour(k - 1, a + c <= va ? a + c : va, b, 0, a0, b0, c0);
    pour(k - 1, 0, b, a + c <= vc ? c + a : vc, a0, b0, c0);
  }
  else if (k == 0)
    return 0;
}
