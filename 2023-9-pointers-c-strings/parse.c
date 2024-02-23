#include <stdio.h>

int search(char letter, char rule[]);
int main()
{
  int num = 0;
  char rule[1350] = "", cmd[10300] = "", title[10300] = "", value[10300] = "";
  scanf("%s", rule);
  getchar();
  gets(cmd);
  for (int i = 10299; i >= 1; i--) // clear excess blanks
    if (cmd[i] == '\0' && cmd[i - 1] == ' ')
      cmd[i - 1] = '\0';

  for (int i = 0; cmd[i] != '\0'; i++) // count numbers of the commands
    if (cmd[i] == ' ')
      num++;
  num++;

  int i = 0;
  while (cmd[i] != ' ' && cmd[i] != '\0') // copy filename to 'title'
  {
    title[i] = cmd[i];
    i++;
  }
  num--;
  int oldNum = num;

  int j = i + 1, position_of_letter; // check 'cmd' and eliminate exceptions
  char letter;
  for (; num > 0; num--)
  {
    while (cmd[j] != ' ' && cmd[j] != '\0')
    {
      if (cmd[j - 1] == ' ' && cmd[j] == '-' && ((cmd[j + 1] >= 65 && cmd[j + 1] <= 90) || (cmd[j + 1] >= 97 && cmd[j + 1] <= 122)) && (cmd[j + 2] == '\0' || cmd[j + 2] == ' '))
      {
        letter = cmd[j + 1];
        position_of_letter = search(letter, rule);
        if (position_of_letter >= 0) // search if the letter exists in 'rule'
        {
          if ((rule[position_of_letter + 1] == ':'))
          {
            if (cmd[j + 3] == '-')
              j = j + 6;
            else if (cmd[j + 2] == '\0') // if ':' follows the letter
            {
              int m = 0;
              while (title[m] != '\0')
              {
                printf("%c", title[m]);
                m++;
              }
              printf(": option requires an argument -- '%c'", letter);
              return 0;
            }
          }
        }
        else // not exist => invalid option
        {
          int m = 0;
          while (title[m] != '\0')
          {
            printf("%c", title[m]);
            m++;
          }
          printf(": invalid option -- '%c'", letter);
          return 0;
        }
        j++;
      }
      else
        j++;
    }
    j++;
  }

  int m = 0; // print title
  while (title[m] != '\0')
  {
    printf("%c", title[m]);
    m++;
  }
  printf("\n");

  j = i + 1;
  num = oldNum;
  for (; num > 0; num--)
  {
    while (cmd[j] != ' ' && cmd[j] != '\0')
    {
      if (cmd[j - 1] == ' ' && cmd[j] == '-' && ((cmd[j + 1] >= 65 && cmd[j + 1] <= 90) || (cmd[j + 1] >= 97 && cmd[j + 1] <= 122)) && (cmd[j + 2] == '\0' || cmd[j + 2] == ' '))
      {
        letter = cmd[j + 1];
        position_of_letter = search(letter, rule);
        if (rule[position_of_letter + 1] == ':') // if ':' follows the letter
        {
          int t = j + 3, k = 0;
          while (cmd[t] != '\0' && cmd[t] != ' ')
          {
            value[k] = cmd[t];
            t++;
            k++;
          }
          j = j + k + 3;
          printf("%c=", letter);

          int n = 0;
          while (value[n] != '\0')
          {
            printf("%c", value[n]);
            n++;
          }
          printf("\n");

          for (int q = 0; q <= 10299; q++)
            value[q] = '\0';
        }
        else // if ':' does not follow the letter
          printf("%c\n", letter);
        j++;
      }
      else
        j++;
    }
    j++;
  }

  return 0;
}

int search(char letter, char rule[])
{
  int i = 0;
  while (rule[i] != '\0')
  {
    if (rule[i] == letter)
      return i;
    else
      i++;
  }
  return -1;
}
