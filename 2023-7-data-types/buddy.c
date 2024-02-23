#include <stdio.h>
#include <math.h>
#define LEN 100005

int main()
{
  int count = 1, n, q, idTemp, spaceTemp, power, id[LEN] = {0}, space[LEN] = {99}, is_free[LEN] = {0} /*record if space is used*/;
  char command;
  scanf("%d%d", &n, &q);
  space[1] = pow(2, n);
  for (int i = 1; i <= q; i++)
  {
    getchar();
    scanf("%c", &command);
    if (command == 'Q')
    {
      printf("%d\n", count);
      for (int j = 1; j <= count; j++)
        is_free == 0 ? printf("0 ") : printf("%d ", id[j]);
      printf("\n");
    }

    if (command == 'A')
    {
      scanf(" %d %d", &idTemp, &spaceTemp);
      for (power = 0; power <= 31; power++)
        if (pow(2, power) == spaceTemp || (pow(2, power - 1) < spaceTemp && pow(2, power) > spaceTemp))
          break;

      for (int j = 1; j <= LEN; j++)
      {
        if (space[j] == 0)
        {
          int copy = j;
          for (int m = 1;;)
          {
            if (space[m] > pow(2, power) && is_free[m] == 0)
            {
              space[m] /= 2;
              for (int num = copy; num >= m + 1; num--)
              {
                space[num] = space[num - 1];
                id[num] = id[num - 1];
                is_free[num] = is_free[num - 1];
              }
              copy++;
              count++;
              if (space[m] == pow(2, power))
              {
                is_free[m] = 1;
                id[m] = idTemp;
                goto end;
              }
            }
            else
              m++;
          }
        }
        if (space[j] == pow(2, power) && is_free[j] == 0)
        {
          is_free[j] = 1;
          id[j] = idTemp;
          break;
        }
      }
    }
  end:;
  }

  return 0;
}