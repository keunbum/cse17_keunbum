#include <bits/stdc++.h>

using namespace std;

inline int T(int x) {
  return (((abs(x) - 1)) << 1) + (int) (x < 0);
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  vector<vector<int>> g(n + n), g_rev(n + n);
  while (m--) {
    int foo, bar;
    cin >> foo >> bar;
    int x = T(foo);
    int y = T(bar);
    g[x ^ 1].push_back(y);
    g_rev[y].push_back(x ^ 1);
    g[y ^ 1].push_back(x);
    g_rev[x].push_back(y ^ 1);
  }
  vector<bool> was(n + n, false);
  vector<int> order;
  function<void(int)> Dfs1 = [&](int v) {
    was[v] = true;
    for (int u : g[v]) {
      if (!was[u]) {
        Dfs1(u);
      }
    }
    order.push_back(v);
  };
  for (int i = 0; i < n + n; i++) {
    if (!was[i]) {
      Dfs1(i);
    }
  }
  int cnt = 0;
  vector<int> c(n + n, -1);
  function<void(int)> Dfs2 = [&](int v) {
    for (int u : g_rev[v]) {
      if (c[u] == -1) {
        c[u] = c[v];
        Dfs2(u);
      }
    }
  };
  for (int i = n + n - 1; i >= 0; i--) {
    int v = order[i];
    if (c[v] == -1) {
      c[v] = cnt++;
      Dfs2(v);
    }
  }
  for (int i = 0; i < n + n; i += 2) {
    if (c[i] == c[i ^ 1]) {
      cout << 0 << '\n';
      return 0;
    }
  }
  cout << 1 << '\n';
  for (int i = 0; i < n + n; i += 2) {
    if (i > 0) {
      cout << ' ';
    }
    cout << (int) (c[i] > c[i ^ 1]);
  }
  cout << '\n';
  return 0;
}
