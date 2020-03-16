#include <stdio.h>
#include <string.h>

#define N 55

int max(int a, int b) { return a > b ? a : b; }

char s[N][N];
int dist[N][N];
int qx[N * N];
int qy[N * N];

int main() {
  int h, w;
  scanf("%d %d", &h, &w);
  for (int i = 0; i < h; i++) {
  	scanf("%s", s[i]);
  }
  int ans = 0;
  for (int sx = 0; sx < h; sx++) {
    for (int sy = 0; sy < w; sy++) {
      if (s[sx][sy] == 'W') continue;
      memset(dist, -1, sizeof(dist));
      int b = 0, e = 1;
      qx[0] = sx;
      qy[0] = sy;
      dist[sx][sy] = 0;
      while (b < e) {
        for (int dir = 0; dir < 4; dir++) {
          int nx = qx[b] + "2101"[dir] - '1';
          int ny = qy[b] + "1210"[dir] - '1';
          if (nx >= 0 && ny >= 0 && nx < h && ny < w && s[nx][ny] == 'L' && dist[nx][ny] == -1) {
            dist[nx][ny] = dist[qx[b]][qy[b]] + 1;
            qx[e] = nx;
            qy[e] = ny;
            ++e;
          }
        }
        ++b;
      }
      ans = max(ans, dist[qx[b - 1]][qy[b - 1]]); 
    }
  }
  printf("%d\n", ans);
  return 0;
}