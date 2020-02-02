#include <iostream>
#include <vector>
#include <functional>

using namespace std;

const int DX[4] = {1, 0, -1, 0};
const int DY[4] = {0, 1, 0, -1};

const int N = 100;
const int MAX = 10010;

int qx[MAX];
int qy[MAX];
int dist[N][N];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  auto IsIn = [&](int x, int y) { return x >= 0 && y >= 0 && x < n && y < n; };
  vector<vector<int>> a(n, vector<int>(n));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> a[i][j];
    }
  }
  int gcnt = 0;
  int ans = n * n;
  vector<vector<int>> grid(n, vector<int>(n, 0));
  vector<vector<int>> was(n, vector<int>(n, 0));
  for (int x = 0; x < n; x++) {
    for (int y = 0; y < n; y++) {
      if (a[x][y] == 0 || grid[x][y] > 0) {
        continue;
      }
      grid[x][y] = ++gcnt;
      was[x][y] = gcnt;
      int b = 0, e = 1;
      qx[0] = x;
      qy[0] = y;
      while (b < e) {
        for (int dir = 0; dir < 4; dir++) {
          int nx = qx[b] + DX[dir];
          int ny = qy[b] + DY[dir];
          if (IsIn(nx, ny) && a[nx][ny] == 1 && grid[nx][ny] == 0) {
            grid[nx][ny] = gcnt;
            was[nx][ny] = gcnt;
            qx[e] = nx;
            qy[e] = ny;
            ++e;
          }
        }
        ++b;
      }
      b = 0;
      while (b < e) {
        for (int dir = 0; dir < 4; dir++) {
          int nx = qx[b] + DX[dir];
          int ny = qy[b] + DY[dir];
          if (IsIn(nx, ny) && was[nx][ny] != gcnt) {
            was[nx][ny] = gcnt;
            if (a[nx][ny] == 0) {
              qx[e] = nx;
              qy[e] = ny;
              dist[nx][ny] = dist[qx[b]][qy[b]] + 1;
              ++e;
            } else {
              ans = min(ans, dist[qx[b]][qy[b]]);
            }
          }
        }
        ++b;
      }
      if (ans == 1) {
        x = y = n;
      }
    }
  }
  cout << ans << '\n';
  return 0;
}
