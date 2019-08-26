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
    x--; y--;
    g[y].push_back(x);
  }
  vector<int> val(n);
  vector<int> was(n, -1);
  int iter;
  function<int(int)> Dfs = [&](int v) {
    was[v] = iter;
    int res = 1;
    for (int to : g[v]) {
      if (was[to] != iter) {
        res += Dfs(to);
      }
    }
    return res;
  };
  int mx = 1;
  for (int i = 0; i < n; i++) {
    iter = i;
    val[i] = Dfs(i);
    mx = max(mx, val[i]);
  }
  vector<int> ans;
  for (int i = 0; i < n; i++) {
    if (val[i] == mx) {
      ans.push_back(i);
    }
  }
  int nn = (int) ans.size();
  for (int i = 0; i < nn; i++) {
    cout << ans[i] + 1 << (i == nn - 1 ? '\n' : ' ');
  }
  return 0;
}
