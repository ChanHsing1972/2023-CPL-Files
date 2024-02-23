#include <stdio.h>

void maxseg(int left, int right);

int len, arr[100005], ans[100005][3];
int main()
{
  scanf("%d", &len);
  for (int i = 1; i <= len; i++)
    scanf("%d", &arr[i]);
  maxseg(1, len);
  for (int i = 1; i <= len; i++)
    printf("%d %d\n", ans[i][1], ans[i][2]);

  return 0;
}

void maxseg(int left, int right)
{
  int max = 0, max_num = 0;
  for (int i = left; i <= right; i++)
    if (arr[i] > max)
    {
      max = arr[i];
      max_num = i;
    }
  ans[max_num][1] = left;
  ans[max_num][2] = right;

  if (left == right)
    ;
  else if (left == max_num)
    maxseg(max_num + 1, right);
  else if (right == max_num)
    maxseg(left, max_num - 1);
  else
  {
    maxseg(max_num + 1, right);
    maxseg(left, max_num - 1);
  }
}