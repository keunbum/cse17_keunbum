#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

struct edge {
  int from, to, cost;
  bool operator<(const edge &o) {
    return cost < o.cost;
  }
};

vector<int> p;
vector<edge> edges;

int get(int v) {
  return v == p[v] ? v : p[v] = get(p[v]);
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  p.resize(n + 1);
  while (m--) {
    int x, y, z;
    cin >> x >> y >> z;
    edges.push_back({ x, y, z });
  }
  sort(edges.begin(), edges.end());
  iota(p.begin(), p.end(), 0);
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