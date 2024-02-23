#include <stdio.h>

struct poly // 开一个没用的结构体
{
  int exp[20005];
} p1, p2, ans1, ans2, ans3;

int main()
{
  int co1, co2;
  char name[15] = "";
  scanf("%d%d%s", &co1, &co2, name);
  int temp1 = co1, temp2 = co2;
  for (temp1; temp1 >= 0; temp1--)
    scanf("%d", &p1.exp[temp1]);
  for (temp2; temp2 >= 0; temp2--)
    scanf("%d", &p2.exp[temp2]);

  // 加法
  for (int i = 0; i <= (co1 > co2 ? co1 : co2); i++)
    ans1.exp[i] = p1.exp[i] + p2.exp[i];
  // 减法
  for (int i = 0; i <= (co1 > co2 ? co1 : co2); i++)
    ans2.exp[i] = p1.exp[i] - p2.exp[i];
  // 乘法
  for (int i = 0; i <= co1; i++)
    for (int j = 0; j <= co2; j++)
      ans3.exp[co1 - i + co2 - j] += p1.exp[co1 - i] * p2.exp[co2 - j];

  /* 除最高次项外，若项的系数为负数，则不输出前面的 +
   * 除常数项外，系数为零的项不输出，系数为 +1 / -1 的项不输出 1
   * 使用 n^p 表示 n 的 p 次方 (p > 1)，p 为 1 时只输出 n，p 为 0 时只输出系数 */

  // 输出：加法
  int flag = 0;
  for (int i = (co1 > co2 ? co1 : co2); i >= 0; i--)
  {
    if (ans1.exp[i] == 0)
    {
      if (ans1.exp[i - 1] > 0 && flag == 1)
        printf("+");
      continue;
    }
    flag = 1;
    if (i == 0)
      printf("%d", ans1.exp[i]);
    else if (i == 1 && ans1.exp[i] != 1 && ans1.exp[i] != -1)
      printf("%d%s", ans1.exp[i], name);
    else if (i == 1 && ans1.exp[i] == -1)
      printf("-%s", name);
    else if (i == 1 && ans1.exp[i] == 1)
      printf("%s", name);
    else if (ans1.exp[i] != 1 && ans1.exp[i] != -1)
      printf("%d%s^%d", ans1.exp[i], name, i);
    else if (ans1.exp[i] == -1)
      printf("-%s^%d", name, i);
    else if (ans1.exp[i] == 1)
      printf("%s^%d", name, i);

    if (i >= 1 && ans1.exp[i - 1] > 0) // 打印加号
      printf("+");
  }
  if (flag == 0)
    printf("0");
  printf("\n");
  // 输出：减法
  flag = 0;
  for (int i = (co1 > co2 ? co1 : co2); i >= 0; i--)
  {
    if (ans2.exp[i] == 0)
    {
      if (ans2.exp[i - 1] > 0 && flag == 1)
        printf("+");
      continue;
    }
    flag = 1;
    if (i == 0)
      printf("%d", ans2.exp[i]);
    else if (i == 1 && ans2.exp[i] != 1 && ans2.exp[i] != -1)
      printf("%d%s", ans2.exp[i], name);
    else if (i == 1 && ans2.exp[i] == -1)
      printf("-%s", name);
    else if (i == 1 && ans2.exp[i] == 1)
      printf("%s", name);
    else if (ans2.exp[i] != 1 && ans2.exp[i] != -1)
      printf("%d%s^%d", ans2.exp[i], name, i);
    else if (ans2.exp[i] == -1)
      printf("-%s^%d", name, i);
    else if (ans2.exp[i] == 1)
      printf("%s^%d", name, i);

    if (i >= 1 && ans2.exp[i - 1] > 0) // 打印加号
      printf("+");
  }
  if (flag == 0)
    printf("0");
  printf("\n");
  // 输出：乘法
  flag = 0;
  for (int i = co1 + co2; i >= 0; i--)
  {
    if (ans3.exp[i] == 0)
    {
      if (ans3.exp[i - 1] > 0 && flag == 1)
        printf("+");
      continue;
    }
    flag = 1;
    if (i == 0)
      printf("%d", ans3.exp[i]);
    else if (i == 1 && ans3.exp[i] != 1 && ans3.exp[i] != -1)
      printf("%d%s", ans3.exp[i], name);
    else if (i == 1 && ans3.exp[i] == -1)
      printf("-%s", name);
    else if (i == 1 && ans3.exp[i] == 1)
      printf("%s", name);
    else if (ans3.exp[i] != 1 && ans3.exp[i] != -1)
      printf("%d%s^%d", ans3.exp[i], name, i);
    else if (ans3.exp[i] == -1)
      printf("-%s^%d", name, i);
    else if (ans3.exp[i] == 1)
      printf("%s^%d", name, i);

    if (i >= 1 && ans3.exp[i - 1] > 0) // 打印加号
      printf("+");
  }
  if (flag == 0)
    printf("0");
  return 0;
}