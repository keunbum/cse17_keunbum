#include <stdio.h>

#define N 123

typedef struct {
  int x;
  int y;
} Point;

int a[N][N];
Point que[4 * N * N];

int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      scanf("%1d", a[i] + j);
    }
  }
  int e = 0;
  que[e].x = 1, que[e++].y = 1;
  a[1][1] = 2;
  for (int i = 0; i < e; i++) {
    Point p = que[i];
    if (p.x == n && p.y == m) break;
    for (int j = 0; j < 4; j++) {
      int x = p.x + "2101"[j] - '1';
      int y = p.y + "1210"[j] - '1';
      if (a[x][y] != 1) continue;
      a[x][y] = a[p.x][p.y] + 1;
      que[e].x = x, que[e++].y = y; 
    }
  }
  printf("%d\n", a[n][m] - 1);
  return 0;
}