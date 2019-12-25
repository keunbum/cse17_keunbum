#include <iostream>
#include <vector>
#include <functional>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  vector<vector<int>> g(n);
  for (int i = 0; i < n; i++) {
    int t;
    cin >> t;
    while (t--) {
      int j;
      cin >> j;
      j--;
      g[i].push_back(j);
    }
  }
  int iter = 0;
  vector<vector<int>> pa(n, vector<int>(2, -1));
  vector<int> pb(m, -1), was(n, 0);
  function<int(int, int)> dfs = [&](int v, int k) {
    was[v] = iter;
    for (int u : g[v]) {
      if (pb[u] == -1) {
        pa[v][k] = u;
        pb[u] = v;
        return 1;
      }
    }
    for (int u : g[v]) {
      if (was[pb[u]] != iter) {
        if (dfs(pb[u], 0) || dfs(pb[u], 1)) {
          pa[v][k] = u;
          pb[u] = v;
          return 1;
        }
      }
    }
    return 0;
  };
  int ans = 0;
  while (true) {
    iter++;
    int cnt = 0;
    for (int i = 0; i < n; i++) {
      if (pa[i][0] == -1) cnt += dfs(i, 0);
      if (pa[i][1] == -1) cnt += dfs(i, 1);
    }
    if (cnt == 0) {
      break;
    }
    ans += cnt;
  }
  cout << ans << '\n';
  return 0;
}