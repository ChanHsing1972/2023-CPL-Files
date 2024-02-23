#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int cmp(const void *a, const void *b);
char input[10005], *ans[100];
int main()
{
  int i = 0, size = 0;
  char *token, dvd;
  for (int j = 0; j < 100; j++)
    ans[j] = malloc(105); // 给字符串数组的每个元素分配内存
  scanf("%s\n%c", input, &dvd);
  token = strtok(input, &dvd);
  while (token != NULL) // 分割，将每一部分存入字符串数组 ans 中
  {
    size++;
    strcpy(ans[i++], token);
    token = strtok(NULL, &dvd);
  }

  qsort(ans, size, sizeof(char *), cmp);

  for (int j = 0; j < size; j++)
    printf("%s\n", ans[j]);
  return 0;
}

int cmp(const void *a, const void *b)
{
  char *l = *(char **)a;
  char *r = *(char **)b;
  int result = strcmp(l, r);
  return result < 0 ? -1 : (result = 0 ? 0 : 1);
}