#include <iostream>
#include <vector>
#include <functional>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  const int DX[4] = {1, 0, -1, 0};
  const int DY[4] = {0, 1, 0, -1};
  int n;
  cin >> n;
  vector<vector<int>> a(n, vector<int>(n));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> a[i][j];
    }
  }
  int cnt = 0;
  vector<vector<int>> grid(n, vector<int>(n, 0));
  function<void(int, int)> Dfs = [&](int x, int y) {
    for (int dir = 0; dir < 4; dir++) {
      int nx = x + DX[dir];
      int ny = y + DY[dir];
      if (nx >= 0 && ny >= 0 && nx < n && ny < n && a[nx][ny] == 1 && grid[nx][ny] == 0) {
        grid[nx][ny] = grid[x][y];
        Dfs(nx, ny);
      }
    }
  };
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (a[i][j] == 1 && grid[i][j] == 0) {
        grid[i][j] = ++cnt;
        Dfs(i, j);
      }
    }
  }
  int ans = n * n;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (a[i][j] == 0) {
        continue;
      }
      for (int k = i; k < n; k++) {
        for (int r = 0; r < n; r++) {
          if (a[k][r] == 1 && grid[k][r] != grid[i][j]) {
            ans = min(ans, abs(i - k) + abs(j - r) - 1);
          }
          if (ans == 1) {
            i = j = k = r = n;
            break;
          }
        }
      }
    }
  }
  cout << ans << '\n';
  return 0;
}
