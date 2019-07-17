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
    int m, n;
    cin >> m >> n; // n is number of students
    vector<vector<int>> g(n);
    vector<int> pa(n, -1), pb(m, -1), was(n, 0);
    for (int i = 0; i < n; i++) {
      int x, y;
      cin >> x >> y;
      x--; y--;
      for (int j = x; j <= y; j++) {
        g[i].push_back(j);
      }
    }
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
      int cnt = 0;
      for (int i = 0; i < n; i++) {
        if (pa[i] == -1 && dfs(i)) cnt++;
      }
      if (cnt == 0) break;
      ans += cnt;
    }
    cout << ans << '\n';
  }
  return 0;
}