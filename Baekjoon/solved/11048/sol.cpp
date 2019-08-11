#include <iostream>
#include <vector>

using namespace std;

const int DX[3] = { 0, -1, -1 };
const int DY[3] = { -1, -1, 0 };

const int MAX = 1000;

int F[MAX][MAX];

int Dfs(int x, int y, vector<vector<int>>& grid) {
  if (F[x][y] >= 0) {
    return F[x][y];
  }
  int n = (int) grid.size();
  int m = (int) grid[0].size();
  int res = 0;
  for (int dir = 0; dir < 3; dir++) {
    int nx = x + DX[dir];
    int ny = y + DY[dir];
    if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
      res = max(res, Dfs(nx, ny, grid));
    }
  }
  return F[x][y] = res + grid[x][y];
}

int Solve(vector<vector<int>>& grid) {
  int n = (int) grid.size();
  int m = (int) grid[0].size();
  fill_n(F[0], MAX * MAX, -1);
  return Dfs(n - 1, m - 1, grid);
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  vector<vector<int>> a(n, vector<int>(m));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> a[i][j];
    }
  }
  cout << Solve(a) << '\n';
  return 0;
}