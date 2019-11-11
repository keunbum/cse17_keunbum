#include <bits/stdc++.h>

using namespace std;

const int DX[4] = {1, 0, -1, 0};
const int DY[4] = {0, 1, 0, -1};

const int MAX = 10010;
const int INF = (int) 1e9;

int qx[MAX];
int qy[MAX];

void RunBfs(vector<vector<int>>& a, int sx, int sy, vector<vector<int>>& dist) {
  int n = (int) a.size();
  int m = (int) a[0].size();
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      dist[i][j] = INF;
    }
  }
  int b = 0, e = 1;
  qx[0] = sx;
  qy[0] = sy;
  dist[sx][sy] = 0;
  while (b < e) {
    for (int dir = 0; dir < 4; dir++) {
      int nx = qx[b] + DX[dir];
      int ny = qy[b] + DY[dir];
      if (nx >= 0 && ny >= 0 && nx < n && ny < m && a[nx][ny] != 1 && dist[nx][ny] == INF) {
        qx[e] = nx;
        qy[e] = ny;
        dist[nx][ny] = dist[qx[b]][qy[b]] + 1;
        ++e;
      }
    }
    ++b;
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m, t;
  cin >> n >> m >> t;
  vector<vector<int>> a(n, vector<int>(m));
  int gx = -1, gy = -1;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> a[i][j];
      if (a[i][j] == 2) {
        gx = i;
        gy = j;
      }
    }
  }
  vector<vector<int>> dist(n, vector<int>(m));
  RunBfs(a, 0, 0, dist);
  int bar = dist[n - 1][m - 1];
  int foo = dist[gx][gy];
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      a[i][j] = 0;
    }
  }
  RunBfs(a, gx, gy, dist);
  int mn = min(bar, foo + dist[n - 1][m - 1]);
  cout << (mn <= t ? to_string(mn) : "Fail") << '\n';
  return 0;
}
