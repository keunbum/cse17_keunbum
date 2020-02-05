#include <iostream>
#include <vector>
#include <functional>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, root, tt;
  cin >> n >> root >> tt;
  --root;
  vector<vector<int>> g(n);
  for (int i = 0; i < n - 1; i++) {
    int x, y;
    cin >> x >> y;
    --x; --y;
    g[x].push_back(y);
    g[y].push_back(x);
  }
  vector<int> sz(n);
  function<void(int, int)> Dfs = [&](int v, int p) {
    sz[v] = 1;
    for (int u : g[v]) {
      if (u != p) {
        Dfs(u, v);
        sz[v] += sz[u];
      }
    }
  };
  Dfs(root, -1);
  while (tt--) {
    int v;
    cin >> v;
    --v;
    cout << sz[v] << '\n';
  }
  return 0;
}
