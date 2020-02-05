#include <iostream>
#include <vector>
#include <functional>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<vector<int>> g(n);
  for (int i = 0; i < n - 1; i++) {
    int x, y;
    cin >> x >> y;
    --x; --y;
    g[x].push_back(y);
    g[y].push_back(x);
  }
  vector<int> q(n);
  for (int i = 0; i < n; i++) {
    cin >> q[i];
    --q[i];
  }
  if (q[0] != 0) { cout << 0 << '\n'; return 0; }
  int b = 1;
  function<void(int)> Dfs = [&](int v) {
    while (true) {
      bool ok = false;
      for (int u : g[v]) {
        if (u == q[b]) {
          ++b;
          ok = true;
          if (b != n) {
            Dfs(u);
          }
          break;
        }
      }
      if (!ok || b == n) {
        break;
      }
    }
  };
  Dfs(0);
  cout << (b == n) << '\n';
  return 0;
}
