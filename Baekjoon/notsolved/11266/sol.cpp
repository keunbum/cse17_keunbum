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
  while (m--) {
    int x, y;
    cin >> x >> y;
    --x; --y;
    g[x].push_back(y);
    g[y].push_back(x);
  }
  vector<int> min_depth(n);
  vector<int> depth(n);
  vector<bool> was(n, false);
  vector<int> p(n, -1);
  vector<bool> cutpoint(n, false);
  function<void(int, int)> Dfs = [&](int v, int d) {
    int child_cnt = 0;
    was[v] = true;
    depth[v] = d;
    min_depth[v] = d;
    for (int u : g[v]) {
      if (!was[u]) {
        ++child_cnt;
        p[u] = v;
        Dfs(u, d + 1);
        if (min_depth[u] >= depth[v]) {
          cutpoint[v] = true;
        }
        min_depth[v] = min(min_depth[v], min_depth[u]);
      } else
      if (u != p[v]) {
        min_depth[v] = min(min_depth[v], depth[u]);
      }
    }
    if (p[v] == -1 && child_cnt < 2) {
      cutpoint[v] = false;
    }
  };
  for (int v = 0; v < n; v++) {
    if (!was[v]) {
      Dfs(v, 0);
    }
  }
  vector<int> ans;
  for (int v = 0; v < n; v++) {
    if (cutpoint[v]) {
      ans.push_back(v);
    }
  }
  int sz = (int) ans.size();
  cout << sz << '\n';
  for (int i = 0; i < sz; i++) {
    if (i > 0) {
      cout << ' ';
    }
    cout << ans[i] + 1;
  }
  cout << '\n';
  return 0;
}
