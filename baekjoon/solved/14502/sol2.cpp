#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

const int DX[4] = { 1, 0, -1, 0 };
const int DY[4] = { 0, 1, 0, -1 };

void Dfs(int x, int y, vector<vector<int>>& grid) {
  int n = (int) grid.size();
  int m = (int) grid[0].size();
  for (int dir = 0; dir < 4; dir++) {
    int nx = x + DX[dir];
    int ny = y + DY[dir];
    if (nx >= 0 && nx < n && ny >= 0 && ny < m && grid[nx][ny] == 0) {
      grid[nx][ny] = 2;
      Dfs(nx, ny, grid);
    } 
  }
}

int Cnt(vector<vector<int>> grid) {
  int n = (int) grid.size();
  int m = (int) grid[0].size();
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (grid[i][j] == 2) {
        Dfs(i, j, grid);
      }
    }
  }
  int res = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      res += (grid[i][j] == 0);
    }
  } 
  return res;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  vector<vector<int>> a(n, vector<int>(m));
  vector<int> X, Y;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> a[i][j];
      if (a[i][j] == 0) {
        X.push_back(i);
        Y.push_back(j);
      }
    }
  }
  int sz = (int) X.size();
  assert(3 <= sz);
  int ans = 0;
  for (int i = 0; i < sz; i++) {
    for (int j = i + 1; j < sz; j++) {
      for (int k = j + 1; k < sz; k++) {
        a[X[i]][Y[i]] = a[X[j]][Y[j]] = a[X[k]][Y[k]] = 1;
        ans = max(ans, Cnt(a));
        a[X[i]][Y[i]] = a[X[j]][Y[j]] = a[X[k]][Y[k]] = 0;
      }
    }
  }
  cout << ans << '\n';
  return 0;
}