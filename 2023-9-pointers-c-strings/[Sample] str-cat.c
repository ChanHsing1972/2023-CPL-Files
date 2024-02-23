/*********************************
 * A sample by 221870106-Xu Tianxing
 * 2023-12-02 04:28:10
 *********************************/

#include <stdio.h>
#include <string.h>

#define N_MAX 2005

int cal_len(char *s1, char *s2)
{
  int len1 = strlen(s1);
  int len2 = strlen(s2);
  for (int i = len2; i >= 1; i -= 1) // i是截断数组temp的位置，随着i--不断前移（即数组长度不断缩短）
  {
    char temp[N_MAX];
    strcpy(temp, s2);                 // 把s2复制到temp中
    temp[i] = '\0';                   // 将数组元素替换为'\0'来缩短数组temp
    if (!strcmp(s1 + len1 - i, temp)) // 比较两数组尾、首是否相同（利用数组名称=首地址的知识点）
      return i;                       // 若相同则返回截断位置
  }
  return 0;
}

int main()
{
  char s1[N_MAX] = {0}, s2[N_MAX] = {0};
  int t;
  scanf("%d", &t);
  while (t--) // 精简！
  {
    getchar();
    scanf("%s%s", s1, s2);
    int len = cal_len(s1, s2); // 计算两数组尾首相同元素的个数
    strcat(s1, s2 + len);      // 把s1和s2去首（s2 + len）的部分接在一起
    printf("%s\n", s1);
  }
  return 0;
}