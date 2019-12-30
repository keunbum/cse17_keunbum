#include <stdio.h>
#include <string.h>
#include <assert.h>

#define L 100
#define N 222

const int DX[4] = {1, 0, -1, 0};
const int DY[4] = {0, 1, 0, -1};

char s[L + 1];
int a[N][N];

int main()
{
  scanf("%s", s);
  int n = strlen(s);
  int x = 101;
  int y = 101;
  memset(a, -1, sizeof(a));
  a[x][y] = 0;
  for (int i = 1; i <= n; i++)
  {
    switch (s[i - 1])
    {
      case 'U': x--; break;
      case 'L': y--; break;
      case 'R': y++; break;
      case 'D': x++; break;
      default: assert(0);
    }
    if (~a[x][y]) {
      puts("BUG");
      return 0;
    }
    a[x][y] = i;
    for (int dir = 0; dir < 4; dir++)
    {
      int nx = x + DX[dir];
      int ny = y + DY[dir];
      if (~a[nx][ny] && a[nx][ny] != i - 1)
      {
        puts("BUG");
        return 0;
      }  
    }
  }
  puts("OK");
  return 0;
}
