/*********************************
 * A sample by 231250161-Wu Zike
 * 2023-12-02 12:49:42
 *********************************/

#include <stdio.h>
#include <string.h>
char rule[140], name[1000];
int len;
int Judge(char ch)
{
  for (int i = 0; i < len; i++)
  {
    if (rule[i] == ch && rule[i + 1] == ':' && i + 1 < len)
    {
      return 1; // 如果是解析参数就返会1
    }
    else if (rule[i] == ch)
    {
      return -1; // 如果是独立参数就返回-1
    }
  }
  return 0; // 如果不存在就返回0
}
int main()
{
  int i = 0;
  char ch, tem[1050], ans[1050][1050], tem_2[1050];
  scanf("%s", rule);
  len = strlen(rule);
  scanf("%s", name);
  while (scanf("%s", tem) != EOF) // 不断读入数据
  {
    if (tem[0] == '-') // 如果是参数就进入判断
    {
      int flag = Judge(tem[1]);
      if (flag == 0) // 不存在就直接打印
      {
        printf("%s: invalid option -- '%c'", name, tem[1]);
        return 0;
      }
      else if (flag == -1) // 独立参数
      {
        ans[i][0] = tem[1];
        i++;
      }
      else if (flag == 1) // 解析参数
      {
        if (scanf("%s", tem_2) == EOF)
        {
          printf("%s: option requires an argument -- '%c'", name, tem[1]);
          return 0;
        }
        ans[i][0] = tem[1];
        ans[i][1] = '=';
        strcpy(ans[i] + 2, tem_2);
        i++;
      }
    }
    else // 如果是something就继续读入
    {
      continue;
    }
  }
  printf("%s\n", name);
  for (int k = 0; k < i; k++)
  {
    printf("%s\n", ans[k]);
  } // 输出
  return 0;
}