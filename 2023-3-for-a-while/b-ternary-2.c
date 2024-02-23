#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
  int x, n, len, len2, remainder;
  char decimal[20] = {0}, ternary[1000] = {'\0'}, ch;
  scanf("%d", &n);
  for (int j = 0; j < n; j++)
  {
    scanf("%s", &decimal);
    len = strlen(decimal);
    len2 = 0;
    x = atoi(decimal);
    for (int i = 0; i < len; i++)
    {
      if (i == 0 && decimal[i] != '-' && decimal[i] != '1' && decimal[i] != '2' && decimal[i] != '3' && decimal[i] != '4' && decimal[i] != '5' && decimal[i] != '6' && decimal[i] != '7' && decimal[i] != '8' && decimal[i] != '9' && decimal[i] != '0')
      {
        printf("Radix Error");
        goto end;
      }
      else if (i != 0 && decimal[i] != '1' && decimal[i] != '2' && decimal[i] != '3' && decimal[i] != '4' && decimal[i] != '5' && decimal[i] != '6' && decimal[i] != '7' && decimal[i] != '8' && decimal[i] != '9' && decimal[i] != '0')
      {
        printf("Radix Error");
        goto end;
      }
    }

    if (x > 0)
    {
      for (int i = 0;; i++)
      {
        remainder = x % 3;
        if (remainder == 0)
          ternary[i] = '0';
        else if (remainder == 1)
          ternary[i] = '1';
        else if (remainder == 2)
          ternary[i] = '2';
        len2++;
        if (x < 3)
          break;
        x = x / 3;
      }
    }
    else if (x == 0)
      ternary[0] = '0';
    else if (x < 0)
    {
      x = -x;
      for (int i = 0;; i++)
      {
        remainder = x % 3;
        if (remainder == 0)
          ternary[i] = '0';
        else if (remainder == 1)
          ternary[i] = '1';
        else if (remainder == 2)
          ternary[i] = '2';
        len2++;
        if (x < 3)
          break;
        x = x / 3;
      }
    }

    for (int i = 0; i < len2; i++)
    {
      if (ternary[i] == '0' || ternary[i] == '1')
        ;
      else if (ternary[i] == '2')
      {
        ternary[i] = 'Z';
        if (ternary[i + 1] == '\0' || ternary[i + 1] == '0')
          ternary[i + 1] = '1';
        else if (ternary[i + 1] == '1')
          ternary[i + 1] = '2';
        else if (ternary[i + 1] == '2')
          ternary[i + 1] = '3';
      }
      else if (ternary[i] == '3')
      {
        ternary[i] = '0';
        if (ternary[i + 1] == '\0' || ternary[i + 1] == '0')
          ternary[i + 1] = '1';
        else if (ternary[i + 1] == '1')
          ternary[i + 1] = '2';
        else if (ternary[i + 1] == '2')
          ternary[i + 1] = '3';
      }
    }

    if (decimal[0] == '-')
    {
      for (int i = len2; i >= 0; i--)
      {
        if (ternary[i] == 'Z')
          ternary[i] = '1';
        else if (ternary[i] == '1')
          ternary[i] = 'Z';
        else if (ternary[i] == '0')
          ;
      }
    }
    if (ternary[len2] != '\0')
    {
      for (int i = len2; i >= 0; i--)
        printf("%c", ternary[i]);
    }
    else if (ternary[len2] == '\0')
    {
      for (int i = len2 - 1; i >= 0; i--)
        printf("%c", ternary[i]);
    }

  end:
    printf("\n");
    for (int i = 0; i <= 999; i++)
      ternary[i] = '\0';
  }
  return 0;
}
