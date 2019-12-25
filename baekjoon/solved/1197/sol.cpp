#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

struct edge {
  int from, to, cost;
};

vector<int> p;
vector<edge> edges;

int get(int x) {
  return x == p[x] ? x : (p[x] = get(p[x]));
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  p.resize(n);
  iota(p.begin(), p.end(), 0);
  while (m--) {
    int x, y, z;
    cin >> x >> y >> z;
    x--; y--;
    edges.push_back({x, y, z});
  }
  sort(edges.begin(), edges.end(), [&](const edge &a, const edge &b) {
    return a.cost < b.cost;
  });
  int ans = 0;
  for (auto &e : edges) {
    if (get(e.from) != get(e.to)) {
      p[get(e.from)] = get(e.to);
      ans += e.cost;
    }
  }
  cout << ans << '\n';
  return 0;
}