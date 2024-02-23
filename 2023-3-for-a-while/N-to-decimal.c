#include <stdio.h>
#include <math.h>

int main()
{
  int len, N, result = 0;
  char s[35] = {'\0'};
  scanf("%d%d%s", &len, &N, s);

  for (int i = 0; i < len; i++) // 判断字符串是否合法
  {
    if ((N <= 10 && (s[i] < '0' || s[i] > '0' + N - 1)) || (N > 10 && (s[i] < '0' || (s[i] > '0' + N - 1 && s[i] < 'A') || (s[i] > 'A' + N - 11))))
    {
      printf("Error");
      return 0;
    }
  }

  for (int i = 0; i < len; i++)
  {
    if (s[i] <= '9')
      result = result + (s[i] - '0') * pow(N, len - i - 1);
    else if (s[i] >= 'A')
      result = result + (s[i] - 'A' + 10) * pow(N, len - i - 1);
  }
  printf("%d", result);

  return 0;
}