#include <iostream>
#include <vector>
#include <functional>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> g(n);
    while (m--) {
      int x, y;
      cin >> x >> y;
      g[x].push_back(y);
    }
    vector<int> pa(n, -1), pb(n, -1), was(n, 0);
    int iter = 0;
    function<bool(int)> dfs = [&](int v) {
      was[v] = iter;
      for (int u : g[v]) {
        if (pb[u] == -1) {
          pa[v] = u;
          pb[u] = v;
          return true;
        }
      }
      for (int u : g[v]) {
        if (was[pb[u]] != iter && dfs(pb[u])) {
          pa[v] = u;
          pb[u] = v;
          return true;
        }
      }
      return false;
    };
    int ans = 0;
    while (true) {
      iter++;
      int add = 0;
      for (int i = 0; i < n; i++) {
        if (pa[i] == -1) {
          add += (int) dfs(i);
        }
      }
      if (add == 0) break;
      ans += add;
    }
    cout << ans << '\n';
  }
  return 0;
}