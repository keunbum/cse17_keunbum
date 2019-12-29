#include <bits/stdc++.h>

using namespace std;

const int MAX = 40010;
const int K = 30;

int qx[MAX * (K + 1)];
int qy[MAX * (K + 1)];
int qk[MAX * (K + 1)];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  const int DX[4] = {1, 0, -1, 0};
  const int DY[4] = {0, 1, 0, -1};
  const int KX[8] = {2, 1, -1, -2, -2, -1, 1, 2};
  const int KY[8] = {1, 2, 2, 1, -1, -2, -2, -1};
  int k, w, h;
  cin >> k >> w >> h;
  vector<vector<int>> a(h, vector<int>(w));
  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      cin >> a[i][j];
    }
  }
  auto IsIn = [&](int x, int y) {
    return (x >= 0 && y >= 0 && x < h && y < w);
  };
  int b = 0, e = 1;
  qx[0] = 0;
  qy[0] = 0;
  qk[0] = k;
  vector<vector<vector<int>>> dist(h, vector<vector<int>>(w, vector<int>(K + 1, -1)));
  dist[0][0][k] = 0;
  while (b < e) {
    for (int dir = 0; dir < 4; dir++) {
      int nx = qx[b] + DX[dir];
      int ny = qy[b] + DY[dir];
      if (IsIn(nx, ny) && a[nx][ny] == 0 && dist[nx][ny][qk[b]] == -1) {
        qx[e] = nx;
        qy[e] = ny;
        qk[e] = qk[b];
        dist[nx][ny][qk[b]] = dist[qx[b]][qy[b]][qk[b]] + 1;
        ++e;
      }
    }
    if (qk[b] > 0) {
      for (int dir = 0; dir < 8; dir++) {
        int nx = qx[b] + KX[dir];
        int ny = qy[b] + KY[dir];
        if (IsIn(nx, ny) && a[nx][ny] == 0 && dist[nx][ny][qk[b] - 1] == -1) {
          qx[e] = nx;
          qy[e] = ny;
          qk[e] = qk[b] - 1;
          dist[nx][ny][qk[b] - 1] = dist[qx[b]][qy[b]][qk[b]] + 1;
          ++e;
        }        
      }
    }
    ++b;
  }
  int ans = w * h;
  bool ok = false;
  for (int i = 0; i <= k; i++) {
    if (dist[h - 1][w - 1][i] != -1 && dist[h - 1][w - 1][i] < ans) {
      ok = true;
      ans = dist[h - 1][w - 1][i];
    }
  }
  cout << (ok ?  ans : -1) << '\n';
  return 0;
}
