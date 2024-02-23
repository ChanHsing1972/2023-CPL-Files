#include <stdio.h>
#include <string.h>

int main()
{
  int t;
  char s1[2005] = "", s2[2005] = "";
  scanf("%d", &t);
  for (int i = 1; i <= t; i++)
  {
    getchar();
    scanf("%s%s", s1, s2);
    int len1 = strlen(s1), len2 = strlen(s2), m = 0, n = 0, count = 0, oldM;
    for (;;)
    {
      if (m == len1)
        break;
      if (s1[m] != s2[n])
      {
        if (count > 0)
          m = oldM + 1;
        count = 0;
        n = 0;
      }
      if (s1[m] == s2[n])
      {
        if (count == 0)
          oldM = m;
        count++;
        n++;
      }
      m++;
    }

    for (int j = 0; j <= len1 - 1; j++)
      printf("%c", s1[j]);
    for (int j = count; j <= len2 - 1; j++)
      printf("%c", s2[j]);
    printf("\n");
    for (int j = 0; j <= 1004; j++)
    {
      s1[j] = '\0';
      s2[j] = '\0';
    }
  }

  return 0;
}