#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, k;
  cin >> n >> k;
  vector<vector<int>> g(n);
  while (k--) {
    int x, y;
    cin >> x >> y;
    x--; y--;
    g[x].push_back(y);
  }
  vector<vector<int>> adj(n, vector<int>(n));
  function<void(int, int)> Dfs = [&](int v, int u) {
    for (int to : g[u]) {
      if (!adj[v][to]) {
        adj[v][to] = 1;
        Dfs(v, to);
      }
    }
  };
  for (int i = 0; i < n; i++) {
    Dfs(i, i);
  }
  int s;
  cin >> s;
  while (s--) {
    int x, y;
    cin >> x >> y;
    x--; y--;
    cout << (adj[y][x] - adj[x][y]) << '\n';
  }
  return 0;
}
