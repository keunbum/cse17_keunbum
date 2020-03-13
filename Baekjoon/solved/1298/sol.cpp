#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  vector<vector<int>> g(n);
  while (m--) {
    int x, y;
    cin >> x >> y;
    --x; --y;
    g[x].push_back(y);
  }
  vector<int> pa(n, -1);
  vector<int> pb(n, -1);
  vector<int> was(n, 0);
  int iter = 0;
  function<bool(int)> Dfs = [&](int v) {
    was[v] = iter;
    for (int u : g[v]) {
      if (pb[u] == -1) {
        pa[v] = u;
        pb[u] = v;
        return true;
      }
    }
    for (int u : g[v]) {
      if (was[pb[u]] != was[v] && Dfs(pb[u])) {
        pa[v] = u;
        pb[u] = v;
        return true;
      }
    }
    return false;
  };
  int ans = 0;
  while (true) {
    ++iter;
    int cnt = 0;
    for (int i = 0; i < n; i++) {
      cnt += (pa[i] == -1 && Dfs(i));
    }
    if (cnt == 0) {
      break;
    }
    ans += cnt;
  }
  cout << ans << '\n';
  return 0;
}
