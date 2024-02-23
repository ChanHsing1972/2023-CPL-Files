#include <stdio.h>
#define STACK_SIZE 10000
void push(char m);
void pop(void);
void top(void);
void print(void);

char content[STACK_SIZE + 1];
int topNum = STACK_SIZE;
int main()
{
  int n;
  char command[10] = "", ch;
  scanf("%d", &n);
  getchar();
  for (int i = 1; i <= n; i++)
  {
    gets(command);
    if (command[0] == 'p' && command[1] == 'u')
      push(command[5]);
    else if (command[0] == 'p' && command[1] == 'o')
      pop();
    else if (command[0] == 't' && command[1] == 'o')
      top();
    else if (command[0] == 'p' && command[1] == 'r')
      print();
    else
      i--;

    for (int j = 0; j <= 9; j++)
      command[j] = '\0';
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

void top(void)
{
  if (topNum == STACK_SIZE)
    printf("Empty\n");
  else
    printf("%c\n", content[topNum + 1]);
}

void print(void)
{
  if (topNum == STACK_SIZE)
    printf("Empty\n");
  else
  {
    for (int i = topNum + 1; i <= STACK_SIZE; i++)
    {
      printf("| %c |\n", content[i]);
      if (i == STACK_SIZE)
      {
        printf("|===|\n");
        break;
      }
    }
  }
}