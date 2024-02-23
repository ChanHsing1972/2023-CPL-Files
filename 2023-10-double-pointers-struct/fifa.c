#include <stdio.h>
#include <string.h>

struct Information
{
  char crew[25];
  int a;
  int b;
  int c;
} info[1005][15];

char team[1005][25], tempTeam[1005][25];
int main()
{
  int n, i = -1, sumA, sumB, sumC;
  double avg[1005][3] = {0};
  scanf("%d", &n);
  int tempN = n;
  while (tempN--) // 储存球员数据
  {
    scanf("%s", &team[++i]);     // i 代表队伍
    for (int j = 0; j < 11; j++) // j 代表每支队伍中的球员
    {
      scanf("%s", &info[i][j].crew);
      scanf("%d", &info[i][j].a);
      scanf("%d", &info[i][j].b);
      scanf("%d", &info[i][j].c);
    }
  }

  for (int m = 0; m < n; m++) // 求平均值，存入 avg
  {
    sumA = sumB = sumC = 0;
    for (int j = 0; j < 11; j++)
    {
      sumA += info[m][j].a;
      sumB += info[m][j].b;
      sumC += info[m][j].c;
    }
    avg[m][0] = sumA / 11.0;
    avg[m][1] = sumB / 11.0;
    avg[m][2] = sumC / 11.0;
  }

  for (int k = 0; k <= 2; k++) // k 指代 avg 中的列，即三项数据
  {
    memcpy(tempTeam, team, sizeof(team)); // 把 team 复制到 tempTeam 中暂存
    for (int p = 0; p < n - 1; p++)       // bubble sort，p 为趟数，m 为每趟中进行的次数
      for (int m = 0; m < n - 1 - p; m++)
      {
        if (avg[m][k] < avg[m + 1][k])
        {
          double temp = avg[m][k]; // 交换非降序的 avg
          avg[m][k] = avg[m + 1][k];
          avg[m + 1][k] = temp;

          char tempArr[25] = ""; // 同时交换对应的 tempTeam
          strcpy(tempArr, tempTeam[m]);
          strcpy(tempTeam[m], tempTeam[m + 1]);
          strcpy(tempTeam[m + 1], tempArr);
        }
      }
    for (int m = 0; m < n; m++)
      printf("%s ", tempTeam[m]);
    printf("\n");
  }

  return 0;
}