#include <stdio.h>
#include <stdlib.h>

int cmp(const void *left, const void *right);
int main()
{
  int n, q, *p, key;
  scanf("%d%d", &n, &q);
  int *input = (int *)malloc(sizeof(*input) * n);
  for (int i = 0; i <= n - 1; i++)
    scanf("%d", &input[i]);
  while (q--)
  {
    scanf("%d", &key);
    p = bsearch(&key, input, n, sizeof(input[0]), cmp);
    if (p == NULL)
      printf("-1\n");
    else
      printf("%d\n", p - input);
  }
  return 0;
  free(input);
}

int cmp(const void *left, const void *right)
{
  return *(int *)left - *(int *)right;
}