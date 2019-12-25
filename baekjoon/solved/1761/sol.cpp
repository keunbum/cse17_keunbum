#include <bits/stdc++.h>

using namespace std;

struct Edge {
  int from;
  int to;
  int cost;
  Edge(int _from, int _to, int _cost) : from(_from), to(_to), cost(_cost) {
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<Edge> edges;
  vector<vector<int>> g(n);
  for (int i = 0; i < n - 1; i++) {
    int x, y, z;
    cin >> x >> y >> z;
    x--; y--;
    int id = (int) edges.size();
    g[x].push_back(id);
    g[y].push_back(id);
    edges.emplace_back(x, y, z);
  }
  int order = 0;
  vector<int> pv(n, -1), depth(n, -1), pos(n), en(n), ad(n, -1);
  depth[0] = 0;
  ad[0] = 0;
  function<void(int)> Dfs = [&](int v) {
    pos[v] = order++;
    for (int id : g[v]) {
      const Edge &e = edges[id];
      int u = e.from ^ e.to ^ v;
      if (depth[u] < 0) {
        depth[u] = depth[v] + 1;
        pv[u] = v;
        ad[u] = ad[v] + e.cost;        
        Dfs(u);
      }
    }
    en[v] = order - 1;
  };
  Dfs(0);
  int max_depth = *max_element(depth.begin(), depth.end());
  int h = (int) log2(max_depth) + 1;
  vector<vector<int>> pr(n, vector<int>(h));
  for (int i = 0; i < n; i++) {
    pr[i][0] = pv[i];
  }
  for (int j = 1; j < h; j++) {
    for (int i = 0; i < n; i++) {
      pr[i][j] = pr[i][j - 1] == -1 ? -1 : pr[pr[i][j - 1]][j - 1];
    }
  }
  auto IsAnc = [&](int x, int y) {
    return pos[x] <= pos[y] && en[y] <= en[x];
  };
  auto GetLca = [&](int x, int y) {
    if (IsAnc(x, y)) {
      return x;
    }
    if (IsAnc(y, x)) {
      return y;
    }
    if (depth[x] > depth[y]) {
      swap(x, y);
    }
    for (int i = (int) log2(depth[x]); i >= 0; i--) {
      if (pr[x][i] != -1 && (!IsAnc(pr[x][i], y))) {
        x = pr[x][i];
      }
    }
    return pr[x][0];
  };
  auto GetDis = [&](int x, int y) {
    int lca = GetLca(x, y);
    return ad[x] - ad[lca] + ad[y] - ad[lca];
  };
  int m;
  cin >> m;
  while (m--) {
    int x, y;
    cin >> x >> y;
    x--; y--;
    cout << GetDis(x, y) << '\n';
  }
  return 0;
}
