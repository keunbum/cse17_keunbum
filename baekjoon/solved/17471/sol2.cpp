#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> p(n);
  for (int i = 0; i < n; i++) {
    cin >> p[i];
  }
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
  const int inf = (int) 1e9;
  int ans = inf;
  for (int t = 1; t < (1 << n) - 1; t++) {
    int foo = 0;
    vector<int> c(n);
    for (int i = 0; i < n; i++) {
      c[i] = (t >> i) & 1;
      foo += c[i] ? p[i] : -p[i];
    }
    vector<bool> was(n);
    function<void(int)> Dfs = [&](int v) {
      was[v] = true;
      for (int u : g[v]) {
        if (!was[u] && c[v] == c[u]) {
          Dfs(u);
        }
      }
    };
    int cnt = 0;
    for (int i = 0; i < n; i++) {
      if (!was[i]) {
        Dfs(i);
        cnt++;
      }
    }
    if (cnt == 2) {
      ans = min(ans, abs(foo));
    }
  }
  cout << (ans == inf ? -1 : ans) << '\n';
  return 0;
}
