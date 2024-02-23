#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main()
{
  char *text = malloc(4100);
  gets(text);
  int len = strlen(text);
  toupper(*(text));
  for (int i = 1; i < len; i++)
  {
    if (*(text + i) == ' ')
      toupper(*(text + i + 1));
    else
      tolower(*(text + i));
  }
  for (int i = 0; i < len; i++)
    printf("%c", *(text + i));

  return 0;
}