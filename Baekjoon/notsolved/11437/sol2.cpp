#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int n, h;
vector<vector<int>> g, pr;
vector<int> pv, order, pos, sz, depth, root, en;

void dfs(int v) {
  pos[v] = (int) order.size();
  order.push_back(v);
  sz[v] = 1;
  for (int u : g[v]) {
    if (depth[u] >= 0) {
      continue;
    }
    depth[u] = depth[v] + 1;
    pv[u] = v;
    root[u] = root[v];
    dfs(u);
    sz[v] += sz[u];
  }
  en[v] = (int) order.size() - 1;
}

void build() {
  int max_depth = *max_element(depth.begin(), depth.end());
  h = 1;
  while ((1 << h) <= max_depth) {
    h++;
  }
  pr.resize(n);
  for (int i = 0; i < n; i++) {
    pr[i].resize(h);
    pr[i][0] = pv[i];
  }
  for (int j = 1; j < h; j++) {
    for (int i = 0; i < n; i++) {
      pr[i][j] = pr[i][j - 1] == -1 ? -1 : pr[pr[i][j - 1]][j - 1];
    }
  }
}

inline bool anc(int x, int y) {
  return pos[x] <= pos[y] && en[y] <= en[x];
}

inline int lca(int x, int y) {
  if (anc(x, y)) return x;
  if (anc(y, x)) return y;
  if (depth[x] > depth[y]) swap(x, y);
  for (int j = log2(depth[x]); j >= 0; j--) {
    if (pr[x][j] != -1 && !anc(pr[x][j], y)) {
      x = pr[x][j];
    }
  }
  return pr[x][0];
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> n;
  g.resize(n);
  pv.resize(n, -1);
  pos.resize(n, -1);
  sz.resize(n, 0);
  depth.resize(n, -1);
  root.resize(n, -1);
  en.resize(n, -1);
  for (int i = 0; i < n - 1; i++) {
    int x, y;
    cin >> x >> y;
    x--; y--;
    g[x].push_back(y);
    g[y].push_back(x);
  }
  depth[0] = 0;
  root[0] = 0;
  dfs(0);
  build();
  int m;
  cin >> m;
  while (m--) {
    int x, y;
    cin >> x >> y;
    x--; y--;
    cout << lca(x, y) + 1 << '\n';
  }
  return 0;
}