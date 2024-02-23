#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main()
{
  int t, ds1, ds2, size;
  char *input = (char *)malloc(6010 * sizeof(*input));
  char *s1 = (char *)malloc(1005 * sizeof(*s1));
  char *s2 = (char *)malloc(1005 * sizeof(*s2));
  if (s1 == NULL || s2 == NULL)
    return 0;
  scanf("%d", &t);
  while (t--)
  {
    getchar();
    scanf("%s", input);
    s1 = strtok(input, ";");
    s2 = strtok(NULL, ";");
    ds1 = atoi(strtok(NULL, ";"));
    ds2 = atoi(strtok(NULL, ";"));
    size = atoi(strtok(NULL, ";"));
    char *s3 = (char *)malloc(size * sizeof(*s3));
    if (s3 == NULL)
      return 0;
    for (int i = 0; i <= size - 1; i++)
      *(s3 + i) = '\0';

    int i = 0, j = 0, num = 0, temp1, temp2;
    for (;;)
    {
      temp1 = ds1;
      while (temp1 > 0)
      {
        if (*(s1 + i) == '\0')
          break;
        *(s3 + num) = *(s1 + i);
        i++;
        temp1--;
        if (num == size - 1)
          goto print;
        num++;
      }

      temp2 = ds2;
      while (temp2 > 0)
      {
        if (*(s2 + j) == '\0')
          break;
        *(s3 + num) = *(s2 + j);
        j++;
        temp2--;
        if (num == size - 1)
          goto print;
        num++;
      }

      if ((*(s1 + i) == '\0') && (*(s2 + j) == '\0'))
        break;
    }
  print:
    for (int i = 0; i <= size - 1; i++)
      printf("%c", *(s3 + i));
    printf("\n");
  }

  free(input);
  free(s1);
  free(s2);
  return 0;
}