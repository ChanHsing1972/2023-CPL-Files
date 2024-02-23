#include <stdio.h>

int find(int x);
int a[100005] = {0};
int main()
{
  int n;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++)
    scanf("%d", &a[i]);
  for (int i = 1; i <= n; i++)
    a[i] = find(a[i]);
  for (int i = 1; i <= n; i++)
    printf("%d ", a[i]);
  return 0;
}

int find(int x)
{
  if (x == a[x])
    return x;
  else
    return find(a[x]);
}