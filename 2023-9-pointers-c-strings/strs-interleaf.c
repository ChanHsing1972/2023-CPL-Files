#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main()
{
  int t, ds1, ds2, size;
  char *input = (char *)malloc(16010 * sizeof(*input));
  char *s1 = (char *)malloc(11005 * sizeof(*s1));
  char *s2 = (char *)malloc(11005 * sizeof(*s2));
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
    char *s3 = (char *)malloc(2 * size * sizeof(*s3));
    if (s3 == NULL)
      return 0;
    for (int i = 0; i <= 2 * size - 1; i++)
      *(s3 + i) = '\0';

    int i = 0, j = 0, num = 0, temp1, temp2;
    for (;;)
    {
      if (size == 1)
        goto print;

      temp1 = ds1;
      while (temp1 > 0)
      {
        if (*(s1 + i) == '\0')
          break;
        *(s3 + num) = *(s1 + i);
        i++;
        temp1--;
        if (num == size - 2)
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
        if (num == size - 2)
          goto print;
        num++;
      }

      if ((*(s1 + i) == '\0') && (*(s2 + j) == '\0'))
        break;
    }

    int putout = 0;
  print:
    while (*(s3 + putout) != '\0')
    {
      printf("%c", *(s3 + putout));
      putout++;
    }
    printf("\n");
    free(s3);
  }

  free(s1);
  free(s2);
  free(input);
  return 0;
}