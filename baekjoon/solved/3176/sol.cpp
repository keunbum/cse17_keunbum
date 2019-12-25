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
  const int MAX = (int) 1e9;
  int n;
  cin >> n;
  vector<vector<int>> g(n);
  vector<Edge> edges;
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
  vector<int> pv(n, -1), depth(n, -1), pos(n), en(n), dv(n, -1);
  depth[0] = 0;
  function<void(int)> Dfs = [&](int v) {
    pos[v] = order++;
    for (int id : g[v]) {
      const Edge& e = edges[id];
      int u = e.from ^ e.to ^ v;
      if (depth[u] < 0) {
        depth[u] = depth[v] + 1;
        pv[u] = v;
        dv[u] = e.cost;
        Dfs(u);
      }
    }
    en[v] = order - 1;
  };
  Dfs(0);
  int max_depth = *max_element(depth.begin(), depth.end());
  int h = (int) log2(max_depth) + 1;
  vector<vector<int>> pr(n, vector<int>(h));
  vector<vector<int>> d_min(n, vector<int>(h));
  vector<vector<int>> d_max(n, vector<int>(h));
  for (int i = 0; i < n; i++) {
    pr[i][0] = pv[i];
    d_min[i][0] = dv[i];
    d_max[i][0] = dv[i];
  }
  for (int j = 1; j < h; j++) {
    for (int i = 0; i < n; i++) {
      pr[i][j] = pr[i][j - 1] == -1 ? -1 : pr[pr[i][j - 1]][j - 1];
      d_min[i][j] = pr[i][j - 1] == -1 ? -1 : min(d_min[i][j - 1], d_min[pr[i][j - 1]][j - 1]);
      d_max[i][j] = pr[i][j - 1] == -1 ? -1 : max(d_max[i][j - 1], d_max[pr[i][j - 1]][j - 1]);
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
  auto GetMinMax = [&](int anc, int x) {
    if (anc == x) {
      return make_pair(MAX, 0);
    }
    int dep_dis = depth[x] - depth[anc];
    int mn = MAX;
    int mx = 0;
    for (int i = (int) log2(dep_dis); i >= 0; i--) {
      if (pr[x][i] != -1 && depth[pr[x][i]] >= depth[anc]) {
        mn = min(mn, d_min[x][i]);
        mx = max(mx, d_max[x][i]);
        x = pr[x][i];
      }
    }
    return make_pair(mn, mx);
  };
  int m;
  cin >> m;
  while (m--) {
    int x, y;
    cin >> x >> y;
    x--; y--;
    int lca = GetLca(x, y);
    pair<int, int> ansa = GetMinMax(lca, x);
    pair<int, int> ansb = GetMinMax(lca, y);
    int mn = min(ansa.first, ansb.first);
    int mx = max(ansa.second, ansb.second);
    cout << mn << ' ' << mx << '\n';
  }
  return 0;
}
