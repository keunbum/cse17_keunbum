#include <bits/stdc++.h>

using namespace std;

const int DX[8] = {1, 1, 0, -1, -1, -1, 0, 1};
const int DY[8] = {0, 1, 1, 1, 0, -1, -1, -1};

int a[10][10];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  int cnt = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> a[i][j];
      cnt += (int) (a[i][j] == 2);
    }
  }
  function<void(int)> Dfs = [&](int c) {
    if (c == 1) {
      cout << "Possible" << '\n';
      exit(0);
    }
    for (int x = 0; x < n; x++) {
      for (int y = 0; y < n; y++) {
        if (a[x][y] < 2) {
          continue;
        }
        for (int dir = 0; dir < 8; dir++) {
          int nx = x + DX[dir];
          int ny = y + DY[dir];
          int nnx = nx + DX[dir];
          int nny = ny + DY[dir];
          if (a[nx][ny] == 2 && a[nnx][nny] == 0) {
            a[x][y] = a[nx][ny] = 0;
            a[nnx][nny] = 2;
            Dfs(c - 1);
            a[x][y] = a[nx][ny] = 2;
            a[nnx][nny] = 0;            
          }
        }
      }
    }
  };
  Dfs(cnt);
  cout << "Impossible" << '\n';
  return 0;
}
