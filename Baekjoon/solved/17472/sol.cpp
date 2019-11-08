#include <bits/stdc++.h>

using namespace std;

struct Edge {
  int from;
  int to;
  int cost;
  bool operator<(const Edge& o) {
    return cost < o.cost;
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  const int DX[4] = {0, 1, 0, -1};
  const int DY[4] = {1, 0, -1, 0};
  int n, m;
  cin >> n >> m;
  auto IsIn = [&](int x, int y) { return x >= 0 && x < n && y >= 0 && y < m; };
  vector<vector<int>> a(n, vector<int>(m));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> a[i][j];
    }
  }
  vector<vector<int>> grid(n, vector<int>(m));
  int cnt = 0;
  function<void(int, int)> Dfs = [&](int x, int y) {
    for (int dir = 0; dir < 4; dir++) {
      int nx = x + DX[dir];
      int ny = y + DY[dir];
      if (IsIn(nx, ny) && a[nx][ny] == 1 && grid[nx][ny] == 0) {
        grid[nx][ny] = grid[x][y];
        Dfs(nx, ny);
      }
    }
  };
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (a[i][j] == 1 && grid[i][j] == 0) {
        grid[i][j] = ++cnt;
        Dfs(i, j);
      }
    }
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (j > 0) {
        cerr << ' ';
      }
      cerr << grid[i][j];
    }
    cerr << '\n';
  }
  vector<Edge> edges;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (a[i][j] == 0) {
        continue;
      }
      for (int dir = 0; dir < 2; dir++) {
        int l = 0;
        int nx = i + DX[dir];
        int ny = j + DY[dir];
        while (IsIn(nx, ny) && a[nx][ny] == 0) {
          l++;
          nx += DX[dir];
          ny += DY[dir];
        }
        if (l >= 2 && IsIn(nx, ny)) {
          edges.push_back({grid[i][j], grid[nx][ny], l});
        }
      }
    }
  }
  
  for (const Edge& e : edges) {
    cerr << e.from << ' ' << e.to << ' ' << e.cost << '\n';
  }
  sort(edges.begin(), edges.end());
  vector<int> p(cnt + 1);
  iota(p.begin(), p.end(), 0);
  function<int(int)> Get = [&](int x) {
    return (x == p[x] ? x : p[x] = Get(p[x]));
  };
  int ans = 0;
  for (const Edge& e: edges) {
    int F = Get(e.from);
    int T = Get(e.to);
    if (F != T) {
      ans += e.cost;
      p[F] = T;
    }
  }
  bool ok = true;
  for (int i = 1; i < cnt; i++) {
    if (Get(i) != Get(i + 1)) {
      ok = false;
      break;
    }
  }
  
  for (int i = 1; i <= cnt; i++) {
    cerr << i << ": " << p[i] << '\n';
  }
  cout << (ok ? ans : -1) << '\n';
  return 0;
}
