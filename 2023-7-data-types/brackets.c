#include <stdio.h>
#define STACK_SIZE 100010
void push(char m);
void pop(void);

char content[STACK_SIZE + 2];
int topNum = STACK_SIZE;
int main()
{
  int t;
  char s[100010] = "", ch;
  scanf("%d", &t);
  getchar();
  for (int j = 1; j <= t; j++)
  {
    scanf("%s", s);
    for (int i = 0;; i++)
    {
      if (s[i] == '\0' && content[topNum + 1] == '\0')
      {
        printf("True\n");
        break;
      }
      else if (s[i] == '\0' && content[topNum + 1] != '\0')
      {
        printf("False\n");
        break;
      }
      else if (s[i] == '(' || s[i] == '[' || s[i] == '{')
        push(s[i]);
      else if (s[i] == ')' || s[i] == ']' || s[i] == '}')
      {
        if (topNum == STACK_SIZE)
        {
          printf("False\n");
          break;
        }
        else if (s[i] == ')' && (content[topNum + 1] != '('))
        {
          printf("False\n");
          break;
        }
        else if (s[i] == ']' && (content[topNum + 1] != '['))
        {
          printf("False\n");
          break;
        }
        else if (s[i] == '}' && (content[topNum + 1] != '{'))
        {
          printf("False\n");
          break;
        }
        else
          pop();
      }
    }
    topNum = STACK_SIZE;
  }
  return 0;
}

void push(char m)
{
  content[topNum] = m;
  topNum--;
}

void pop(void)
{
  if (topNum == STACK_SIZE)
    printf("Empty\n");
  else
  {
    content[topNum] = '\0';
    topNum++;
  }
}