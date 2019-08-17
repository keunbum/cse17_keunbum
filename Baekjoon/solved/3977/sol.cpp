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
    vector<vector<int>> g(n), g_rev(n);
    while (m--) {
      int x, y;
      cin >> x >> y;
      g[x].push_back(y);
      g_rev[y].push_back(x);
    }
    vector<int> order;
    vector<bool> was(n, false);
    function<void(int)> Dfs1 = [&](int v) {
      was[v] = true;
      for (int u : g[v]) {
        if (!was[u]) {
          Dfs1(u);
        }
      }
      order.push_back(v);
    };
    for (int i = 0; i < n; i++) {
      if (!was[i]) {
        Dfs1(i);
      }
    }
    vector<int> c(n, -1);
    function<void(int)> Dfs2 = [&](int v) {
      for (int u : g_rev[v]) {
        if (c[u] == -1) {
          c[u] = c[v];
          Dfs2(u);
        }
      }
    };
    int cnt = 0;
    for (int i = n - 1; i >= 0; i--) {
      int v = order[i];
      if (c[v] == -1) {
        c[v] = cnt++;
        Dfs2(v);
      }
    }
    fill(was.begin(), was.end(), false);
    for (int i = 0; i < n; i++) {
      if (c[i] == 0 && !was[i]) {
        Dfs1(i);
      }
    }
    bool ok = true;
    for (int i = 0; i < n; i++) {
      if (!was[i]) {
        ok = false;
        break;
      }
    }
    if (ok) {
      for (int i = 0; i < n; i++) {
        if (c[i] == 0) {
          cout << i << '\n';
        }
      }
    } else {
      cout << "Confused" << '\n';
    }
    if (tt > 0) {
      cout << '\n';
    }
  }
  return 0;
}
