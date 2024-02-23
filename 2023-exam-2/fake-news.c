#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main()
{
  char a[10300] = "";
  scanf("%s", a);
  int len = strlen(a);
  for (int i = 1; a[i] != '\0'; i++)
    if (a[i] >= 'A' && a[i] <= 'Z')
    {
      for (int j = len; j >= i + 1; j--)
        a[j] = a[j - 1];
      a[i++] = ' ';
      a[i] = tolower(a[i]);
      len++;
    }
  for (int i = 0; a[i] != '\0'; i++)
    printf("%c", a[i]);

  return 0;
}