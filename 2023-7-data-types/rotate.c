#include <stdio.h>
#include <string.h>

void rotateW(int xa, int ya, int za, int xb, int yb, int zb, int xc, int yc, int zc, int xd, int yd, int zd, int xa1, int ya1, int za1, int xb1, int yb1, int zb1, int xc1, int yc1, int zc1, int xd1, int yd1, int zd1);
void rotateA(int xa, int ya, int za, int xb, int yb, int zb, int xc, int yc, int zc, int xd, int yd, int zd, int xa1, int ya1, int za1, int xb1, int yb1, int zb1, int xc1, int yc1, int zc1, int xd1, int yd1, int zd1);
void rotateS(int xa, int ya, int za, int xb, int yb, int zb, int xc, int yc, int zc, int xd, int yd, int zd, int xa1, int ya1, int za1, int xb1, int yb1, int zb1, int xc1, int yc1, int zc1, int xd1, int yd1, int zd1);
void rotateD(int xa, int ya, int za, int xb, int yb, int zb, int xc, int yc, int zc, int xd, int yd, int zd, int xa1, int ya1, int za1, int xb1, int yb1, int zb1, int xc1, int yc1, int zc1, int xd1, int yd1, int zd1);

int nxa, nya, nza, nxb, nyb, nzb, nxc, nyc, nzc, nxd, nyd, nzd, nxa1, nya1, nza1, nxb1, nyb1, nzb1, nxc1, nyc1, nzc1, nxd1, nyd1, nzd1;
int main()
{
  int a, b, c, len;
  char command[1005] = "";
  scanf("%d%d%d", &a, &b, &c);
  scanf("%s", command);
  len = strlen(command);

  // initialise
  nxa = a;
  nya = 0;
  nza = 0;
  nxb = a;
  nyb = b;
  nzb = 0;
  nxc = 0;
  nyc = b;
  nzc = 0;
  nxd = 0;
  nyd = 0;
  nzd = 0;
  nxa1 = a;
  nya1 = 0;
  nza1 = c;
  nxb1 = a;
  nyb1 = b;
  nzb1 = c;
  nxc1 = 0;
  nyc1 = b;
  nzc1 = c;
  nxd1 = 0;
  nyd1 = 0;
  nzd1 = c;

  for (int i = 0; i <= len; i++)
  {
    switch (command[i])
    {
    case ('W'):
      rotateW(nxa, nya, nza, nxb, nyb, nzb, nxc, nyc, nzc, nxd, nyd, nzd, nxa1, nya1, nza1, nxb1, nyb1, nzb1, nxc1, nyc1, nzc1, nxd1, nyd1, nzd1);
      break;
    case ('A'):
      rotateA(nxa, nya, nza, nxb, nyb, nzb, nxc, nyc, nzc, nxd, nyd, nzd, nxa1, nya1, nza1, nxb1, nyb1, nzb1, nxc1, nyc1, nzc1, nxd1, nyd1, nzd1);
      break;
    case ('S'):
      rotateS(nxa, nya, nza, nxb, nyb, nzb, nxc, nyc, nzc, nxd, nyd, nzd, nxa1, nya1, nza1, nxb1, nyb1, nzb1, nxc1, nyc1, nzc1, nxd1, nyd1, nzd1);
      break;
    case ('D'):
      rotateD(nxa, nya, nza, nxb, nyb, nzb, nxc, nyc, nzc, nxd, nyd, nzd, nxa1, nya1, nza1, nxb1, nyb1, nzb1, nxc1, nyc1, nzc1, nxd1, nyd1, nzd1);
      break;
    default:
      break;
    }
  }
  printf("%d %d %d %d", nxd, nxa, nyd, nyc);
  return 0;
}

void rotateW(int xa, int ya, int za, int xb, int yb, int zb, int xc, int yc, int zc, int xd, int yd, int zd, int xa1, int ya1, int za1, int xb1, int yb1, int zb1, int xc1, int yc1, int zc1, int xd1, int yd1, int zd1)
{
  nxa1 = xd;
  nya1 = yd;
  nza1 = xa - xd;
  nxb1 = xc;
  nyb1 = yc;
  nzb1 = xb - xc;
  nxb = xc;
  nyb = yc;
  nzb = zc;
  nxa = xd;
  nya = yd;
  nza = zd;
  nxd1 = xd - zd1;
  nyd1 = ya;
  nzd1 = xa1 - xd1;
  nxc1 = xc - zc1;
  nyc1 = yb;
  nzc1 = xb1 - xc1;
  nxc = xc - zc1;
  nyc = yc;
  nzc = 0;
  nxd = xd - zd1;
  nyd = yd;
  nzd = 0;
}
void rotateA(int xa, int ya, int za, int xb, int yb, int zb, int xc, int yc, int zc, int xd, int yd, int zd, int xa1, int ya1, int za1, int xb1, int yb1, int zb1, int xc1, int yc1, int zc1, int xd1, int yd1, int zd1)
{
  nxb = xa;
  nyb = ya;
  nzb = za;
  nxb1 = xa;
  nyb1 = ya;
  nzb1 = yb - ya;
  nxc1 = xd;
  nyc1 = yd;
  nzc1 = yc - yd;
  nxc = xd;
  nyc = yd;
  nzc = zd;
  nxa = xa;
  nya = ya - za1;
  nza = 0;
  nxa1 = xa;
  nya1 = ya - za1;
  nza1 = yb - ya;
  nxd1 = xd;
  nyd1 = yd - zd1;
  nzd1 = yc - yd;
  nxd = xd;
  nyd = yd - zd1;
  nzd = 0;
}
void rotateS(int xa, int ya, int za, int xb, int yb, int zb, int xc, int yc, int zc, int xd, int yd, int zd, int xa1, int ya1, int za1, int xb1, int yb1, int zb1, int xc1, int yc1, int zc1, int xd1, int yd1, int zd1)
{
  nxd = xa;
  nyd = ya;
  nzd = za;
  nxc = xb;
  nyc = yb;
  nzc = zb;
  nxc1 = xb;
  nyc1 = yb;
  nzc1 = xb - xc;
  nxd1 = xa;
  nyd1 = ya;
  nzd1 = xa - xd;
  nxa = xa + za1;
  nya = ya;
  nza = 0;
  nxb = xb + zb1;
  nyb = yb;
  nzb = 0;
  nxb1 = xb + zb1;
  nyb1 = yb;
  nzb1 = xb - xc;
  nxa1 = xa + za1;
  nya1 = ya;
  nza1 = xa - xd;
}
void rotateD(int xa, int ya, int za, int xb, int yb, int zb, int xc, int yc, int zc, int xd, int yd, int zd, int xa1, int ya1, int za1, int xb1, int yb1, int zb1, int xc1, int yc1, int zc1, int xd1, int yd1, int zd1)
{
  nxa1 = xb;
  nya1 = yb;
  nza1 = yb - ya;
  nxa = xb;
  nya = yb;
  nza = zb;
  nxd = xc;
  nyd = yc;
  nzd = zc;
  nxd1 = xc;
  nyd1 = yc;
  nzd1 = yc - yd;
  nxb1 = xa1;
  nyb1 = yb + zb1;
  nzb1 = yb1 - ya1;
  nxb = xb1;
  nyb = yb + zb1;
  nzb = 0;
  nxc = xc1;
  nyc = yc + zc1;
  nzc = 0;
  nxc1 = xd1;
  nyc1 = yc + zc1;
  nzc1 = yc1 - yd1;
}