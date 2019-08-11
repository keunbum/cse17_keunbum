#include <iostream>

using namespace std;

int n, m;
const int N = 8;
int a[N][N], grid[N][N];

const int DX[4] = { 1, 0, -1, 0 };
const int DY[4] = { 0, 1, 0, -1 };

void Dfs(int x, int y) {
  for (int dir = 0; dir < 4; dir++) {
    int nx = x + DX[dir];
    int ny = y + DY[dir];
    if (nx >= 0 && nx < n && ny >= 0 && ny < m && grid[nx][ny] == 0) {
      grid[nx][ny] = 2;
      Dfs(nx, ny);
    }
  }
}

int Cnt() {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      grid[i][j] = a[i][j];
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (a[i][j] == 2) {
        Dfs(i, j);
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

void Wall(int v, int& mx) {
  if (v == 3) {
    int cnt = Cnt();
    mx = max(mx, cnt);
    return;
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (a[i][j] == 0) {
        a[i][j] = 1;
        Wall(v + 1, mx);
        a[i][j] = 0;
      }
    }
  }
}

int Solve() {
  int res = 0;
  Wall(0, res);
  return res;
}


int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> a[i][j];
    }
  }
  cout << Solve() << '\n';
  return 0;
}