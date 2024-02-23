#include <stdio.h>
#define LEN 10000
#define INT_MAX 2147483647

int Compare(int temp1, int temp2);
int main()
{
  int n, m, t, a[LEN] = {0}, b[LEN] = {0}, result[LEN] = {0}, minus, count = 0;
  scanf("%d%d%d", &n, &m, &t);
  for (int i = 1; i <= n; i++)
    scanf("%d", &a[i]);
  for (int i = 1; i <= m; i++)
    scanf("%d", &b[i]);
  a[0] = INT_MAX;
  a[n + 1] = INT_MAX;
  // input data

  for (int array_b = 1; array_b <= m; array_b++)
  {
    minus = t - b[array_b]; // first minus numbers in array 'b'
    if (minus <= 0 && t != b[array_b])
    {
      if (array_b == m)
      {
        for (int i = 1; i <= m; i++)
        {
          if (result[i] != 0)
            count++;
        }
        if (count == 0)
        {
          printf("-1");
          return 0;
        }
      }
      result[array_b] = -1;
      continue;
    }
    else // search array 'a' to find a max number smaller than 'minus'
    {
      int low = 1, high = n, mid = (1 + n) / 2, temp1, temp2; // binary search
      for (;;)
      {
        if (a[mid] == minus)
        {
          printf("0");
          return 0;
        }
        else if (a[mid] > minus)
        {
          high = mid - 1;
          mid = (low + high) / 2;
          if (low > high)
          {
            temp1 = minus - a[mid];
            temp2 = minus - a[mid + 1];
            result[array_b] = Compare(temp1, temp2);
            break;
          }
        }
        else if (a[mid] < minus)
        {
          low = mid + 1;
          mid = (low + high) / 2;
          if (low > high)
          {
            temp1 = minus - a[mid];
            temp2 = minus - a[mid + 1];
            result[array_b] = Compare(temp1, temp2);
            break;
          }
        }
      }
    }
  }

  int min = INT_MAX;
  count = 0;
  for (int array_b = 1; array_b <= m; array_b++)
  {
    if (result[array_b] < min && result[array_b] > 0)
      min = result[array_b];
    else if (result[array_b] == -1)
      count++;
  }
  if (count == m)
    printf("-1");
  else
    printf("%d", min);
  return 0;
}

int Compare(int temp1, int temp2)
{
  if (temp1 < 0 && temp2 < 0)
    return -1;
  else if (temp1 < 0)
    return temp2;
  else if (temp2 < 0)
    return temp1;
  else if (temp1 >= temp2)
    return temp2;
  else if (temp1 < temp2)
    return temp1;
}