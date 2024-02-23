#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define LEN 10000

void initialise(char input[]);
int process(char input[]);
int judge(char input[]);
int time = 0, flag1 = 0, flag2 = 0, flag3 = 0;
char ans[10000][15], input[LEN];
int main()
{
  while (scanf("%s", input) != EOF)
  {
    int count = 0, len = strlen(input);
    for (int i = 0; i <= LEN - 1; i++)
      if (input[i] == ';')
        count++;
    if (input[len - 1] != ';')
      flag3 = 1;

    char *position = strchr(input, ';'); // if there's no ';' in s, it returns NULL.
    if (position == NULL)
      process(input);
    else
    {
      while (input[0] == ';')
      {
        ans[time++][0] = '\n';
        for (int i = 0; i <= LEN - 2; i++)
        {
          *(input + i) = *(input + i + 1);
        }
      }
      if (strchr(input, ';') != NULL)
        position = strchr(input, ';');
      process(strtok(input, ";"));

      while (flag2 == 0)
      {
        char *temp = position;
        while (*(temp + 1) == ';')
        {
          ans[time++][0] = '\n';
          for (int i = 0; i <= LEN - 2; i++)
          {
            *(temp + i) = *(temp + i + 1);
          }
          *(temp) = ' ';
          if (strchr(input, ';') != NULL)
            position = strchr(input, ';');
        }
        ans[time++][0] = '\n';
        process(strtok(NULL, ";"));
      }

      if (flag3 == 1)
      {
        time--;
        ans[time][0] = '\0';
      }
    }
    flag2 = 0;
    flag3 = 0;
    initialise(input);
  }
  // print answer
  if (flag1 == 0)
  {
    for (int i = 0; i <= 999; i++)
    {
      if (ans[i][0] == '\0')
        break;
      printf("%s", ans[i]);
    }
  }
  else
    printf("Compile Error");
  return 0;
}

int process(char input[])
{
  if (input == NULL)
  {
    flag2 = 1;
    return -1;
  }
  const char *reserved[16] = {"const", "int", "float", "double", "long", "static", "void", "char", "extern", "return", "break", "enum", "struct", "typedef", "union", "goto"};
  judge(input);
  // 1、保留字 (reserved)
  for (int i = 0; i <= 15; i++)
  {
    if (input[0] == reserved[i][0] && input[1] == reserved[i][1] && input[2] == reserved[i][2])
    {
      strcpy(ans[time++], "reserved ");
      return 0;
    }
  }
  for (int i = 0; input[i] != '\0'; i++)
  {
    if (input[i] == '.' || (input[i] >= '0' && input[i] <= '9'))
      ;
    else
      goto not_a_number;
  }
  // 2、整数 (integer) && 3、浮点数 (float)
  for (int i = 0; input[i] != '\0'; i++)
  {
    if ((input[0] < '0' || input[0] > '9') && input[0] != '.')
      break;
    if (input[i] == '.')
    {
      strcpy(ans[time++], "float ");
      return 0;
    }
    if (input[i + 1] == '\0')
    {
      strcpy(ans[time++], "integer ");
      return 0;
    }
  }
not_a_number:
  // 4、运算符 (operator)
  if (((input[0] == '+' || input[0] == '-' || input[0] == '*' || input[0] == '/' || input[0] == '=' || input[0] == '>' || input[0] == '<') && input[1] == '\0') || ((input[0] == '!' || input[0] == '=' || input[0] == '>' || input[0] == '<') && input[1] == '=' && input[2] == '\0'))
    strcpy(ans[time++], "operator ");
  // 5、变量 (variable)
  else
  {
    for (int i = 0; input[i] != '\0'; i++)
      if ((input[i] != '_') && ((input[i] < '0') || (input[i] > '9' && input[i] < 'A') || (input[i] > 'Z' && input[i] < 'a') || (input[i] > 'z')))
      {
        flag1 = 1;
        return 0;
      }
    strcpy(ans[time++], "variable ");
  }
  return 0;
}

int judge(char input[]) // eliminate illegal input
{
  for (int i = 0; input[i] != '\0'; i++)
    if ((input[i] == '|' && input[i + 1] == '|')                                                                                                                                      // 约定中没有 || 运算符
        || (input[i - 1] == '\0' || i == 0) && (input[i] >= '0' && input[i] <= '9' && ((input[i + 1] >= 'a' && input[i + 1] <= 'z') || (input[i + 1] >= 'A' && input[i + 1] <= 'Z'))) // 变量开头不是数字
        || (input[i] == '-' && ((input[i + 1] >= '0' && input[i + 1] <= '9') || (input[i + 1] == '.'))))                                                                              // 约定中整数不含负号
    {
      flag1 = 1;
      return 0;
    }

  int count = 0; // 处理不合法的浮点数
  for (int i = 0; input[i] != '\0'; i++)
  {
    if (input[i] == '.' || (input[i] >= '0' && input[i] <= '9'))
      ;
    else
      break;
    if (input[i + 1] == '\0')
    {
      for (int j = 0; input[j] != '\0'; j++)
      {
        if (input[j] == '.')
          count++;
      }
      if (count >= 2)
      {
        flag1 = 1;
        return 0;
      }
    }
  }
}

void initialise(char input[])
{
  for (int i = 0; i <= LEN - 1; i++)
    input[i] = '\0';
}
