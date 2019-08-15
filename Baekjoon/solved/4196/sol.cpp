#include <bits/stdc++.h>

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
      x--; y--;
      g[x].push_back(y);
    }
    vector<int> order;
    vector<bool> was(n, false);
    function<void(int)> Dfs1 = [&](int v) {
      for (int u : g[v]) {
        if (!was[u]) {
          was[u] = true;
          Dfs1(u);
        }
      }
      order.push_back(v);
    };
    for (int i = 0; i < n; i++) {
      if (!was[i]) {
        was[i] = true;
        Dfs1(i);
      }
    }
    int cnt = 0;
    vector<int> c(n, -1);
    function<void(int)> Dfs2 = [&](int v) {
      for (int u : g[v]) {
        if (c[u] == -1) {
          c[u] = c[v];
          Dfs2(u);
        }
      }
    };
    for (int i = n - 1; i >= 0; i--) {
      int v = order[i];
      if (c[v] == -1) {
        c[v] = cnt++;
        Dfs2(v);
      }
    }
    /*
    cerr << "Debug" << '\n';
    for (int i = 0; i < n; i++) {
      cerr << "c[" << i << "] = " << c[i] << '\n';
    }
    */
    cout << cnt << '\n';
  }
  return 0;
}
