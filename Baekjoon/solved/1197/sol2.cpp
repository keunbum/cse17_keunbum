#include <iostream>
#include <numeric>
#include <algorithm>

using namespace std;

struct edge {
  int from, to, cost;
  bool operator<(const edge &o) {
    return cost < o.cost;
  }
};

int p[12345];
edge edges[123456];

int get(int v) {
  return v == p[v] ? v : p[v] = get(p[v]);
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    int x, y, z;
    cin >> x >> y >> z;
    edges[i] = { x, y, z };
  }
  sort(edges, edges + m);
  iota(p, p + n, 0);
  int ans = 0;
  for (auto &e : edges) {
    int F = get(e.from);
    int T = get(e.to);
    if (F != T) {
      p[F] = T;
      ans += e.cost;
    }
  }
  cout << ans << '\n';
  return 0;
}