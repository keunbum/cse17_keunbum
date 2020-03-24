#include <stdio.h>
#include <stdlib.h>

#define MAXV 6
#define MAXE 100
#define NM 10

const int DX[4] = {1, 0, -1, 0};
const int DY[4] = {0, 1, 0, -1};

typedef struct {
  int x, y, z;
} Edge;

int a[NM][NM];
int p[MAXV];
Edge edges[MAXE];

int IsIn(int h, int w, int x, int y) {
  return x >= 0 && y >= 0 && x < h && y < w;
}

int Cmp(const void* pi, const void* pj) {
  Edge *ei = (Edge *) pi;
  Edge *ej = (Edge *) pj;
  return ei->z - ej->z;
}

void Dfs(int x, int y, int h, int w) {
  for (int dir = 0; dir < 4; dir++) {
    int nx = x + DX[dir];
    int ny = y + DY[dir];
    if (IsIn(h, w, nx, ny) && a[nx][ny] == -1) {
      a[nx][ny] = a[x][y];
      Dfs(nx, ny, h, w);
    }
  }
  return;
}

int Get(int v) {
  return v == p[v] ? v : (p[v] = Get(p[v]));
}

int main() {
  int h, w;
  scanf("%d%d", &h, &w);
  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      scanf("%d", a[i] + j);
      a[i][j] -= 2;
    }
  }
  int v_cnt = 0;
  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      if (a[i][j] == -1) {
        a[i][j] = v_cnt++;
        Dfs(i, j, h, w);
      }
    }
  }
  int edge_n = 0;
  for (int x = 0; x < h; x++) {
    for (int y = 0; y < w; y++) {
      if (a[x][y] == -2) {
        continue;
      }
      for (int dir = 0; dir < 2; dir++) {
        int nx = x + DX[dir];
        int ny = y + DY[dir];
        int len = 0;
        while (IsIn(h, w, nx, ny) && a[nx][ny] == -2) {
          ++len;
          nx += DX[dir];
          ny += DY[dir];
        }
        if (IsIn(h, w, nx, ny) && a[nx][ny] != a[x][y] && len >= 2) {
          Edge e = {a[x][y], a[nx][ny], len};
          edges[edge_n++] = e;
        }
      }
    }
  }
  qsort(edges, edge_n, sizeof(Edge), Cmp);
  for (int i = 0; i < v_cnt; i++) {
    p[i] = i;
  }
  int ans = 0;
  for (int id = 0; id < edge_n; id++) {
    const Edge *e = edges + id;
    int x = Get(e->x);
    int y = Get(e->y);
    if (x != y) {
      p[x] = y;
      ans += e->z;
    }
  }
  int ok = 1;
  int root = Get(0);
  for (int i = 1; i < v_cnt; i++) {
    if (Get(i) != root) {
      ok = 0;
      break;
    }
  }
  printf("%d\n", ok ? ans : -1); 
  return 0;
}