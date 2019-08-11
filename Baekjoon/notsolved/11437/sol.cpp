#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<vector<int>> g(n);
  for (int i = 0; i < n - 1; i++) {
    int x, y;
    cin >> x >> y;
    x--; y--;
    // 0-indexed vertices
    g[x].push_back(y);
    g[y].push_back(x);
    // undirected graph
  }
  vector<int> pv(n, -1), order, pos(n, -1), depth(n, -1), en(n, -1);
  depth[0] = 0; // 0-indexed depth
  function<void(int)> Dfs = [&](int v) {
    pos[v] = (int) order.size(); // search order
    order.push_back(v);
    for (int u : g[v]) {
      if (depth[u] >= 0) {
        continue;
      }
      depth[u] = depth[v] + 1;
      pv[u] = v; // parent
      Dfs(u);
    }
    en[v] = (int) order.size() - 1;
    // last vertex's index in order in v's subtree
  };
  Dfs(0);
  vector<vector<int>> pr;
  int h;
  auto Build = [&]() {
    int max_depth = *max_element(depth.begin(), depth.end());
    h = 1;
    while ((1 << h) <= max_depth) {
      h++;
    }
    pr.resize(n);
    for (int i = 0; i < n; i++) {
      pr[i].resize(h);
      pr[i][0] = pv[i];
      // the ancestor just above(2^0 = 1th) is the parent
    }
    for (int j = 1; j < h; j++) {
      for (int i = 0; i < n; i++) {
        pr[i][j] = pr[i][j - 1] == -1 ? -1 : pr[pr[i][j - 1]][j - 1];
      }
    }
    
    for (int i = 0; i < n; i++) {
      cerr << i << "'s 2^k-th anc:";
      for (int j = 0; j < h; j++) {
        cerr << ' ' << pr[i][j];
      }
      cerr << '\n';
    }
    
  };
  Build();
  auto Anc = [&](int x, int y) {
    return pos[x] <= pos[y] && en[y] <= en[x];
    // x is y's ancestor
  };
  auto Lca = [&](int x, int y) {
    if (Anc(x, y)) {
      return x;
    }
    if (Anc(y, x)) {
      return y;
    }
    if (depth[x] > depth[y]) {
      swap(x, y);
    }
    for (int j = h - 1; j >= 0; j--) {
      if (pr[x][j] != -1 && !Anc(pr[x][j], y)) {
        x = pr[x][j];
      }
    }
    return pr[x][0];
  };
  int m;
  cin >> m;
  while (m--) {
    int x, y;
    cin >> x >> y;
    x--; y--;
    cout << Lca(x, y) + 1 << '\n';
    // change from 0-indexed to 1-indexed vertex
  }
  return 0;
}
