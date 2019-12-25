#include <stdio.h>

#define N 123

int a[N][N];
int que[4 * N * N][2];

int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      scanf("%1d", a[i] + j);
    }
  }
  int end = 0;
  a[1][1] = 2;
  que[end][0] = 1, que[end++][1] = 1;
  for (int i = 0; i < end; i++) {
    int cx = que[i][0], cy = que[i][1];
    if (a[cx][cy] == a[n][m]) break;
    for (int j = 0; j < 4; j++) {
      int x = cx + "2101"[j] - '1';
      int y = cy + "1210"[j] - '1';
      if (a[x][y] != 1) continue;
      a[x][y] = a[cx][cy] + 1;
      que[end][0] = x, que[end++][1] = y;
    }
  }
  printf("%d\n", a[n][m] - 1);
  return 0;
}