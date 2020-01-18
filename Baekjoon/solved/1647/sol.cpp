#include <bits/stdc++.h>

using namespace std;

struct Edge {
  int from;
  int to;
  int cost;
  bool operator<(const Edge& other) const {
    return cost < other.cost;
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  vector<Edge> edges;
  vector<int> p(n);
  iota(p.begin(), p.end(), 0);
  function<int(int)> Get = [&](int v) {
    return v == p[v] ? v : p[v] = Get(p[v]);
  };
  while (m--) {
    int x, y, z;
    cin >> x >> y >> z;
    --x; --y;
    edges.push_back({x, y, z});
  }
  sort(edges.begin(), edges.end());
  int ans = 0;
  int mx = 0;
  for (const Edge& e : edges) {
    int X = Get(e.from);
    int Y = Get(e.to);
    if (X == Y) {
      continue;
    }
    p[X] = Y;
    ans += e.cost;
    mx = max(mx, e.cost);
  }
  cout << ans - mx << '\n';
  return 0;
}