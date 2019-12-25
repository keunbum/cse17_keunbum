#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <functional>

using namespace std;

struct edge {
  int from, to, cost;
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  while (true) {
    int n, m, k;
    cin >> n >> m >> k;
    if (n == 0) {
      break;
    }
    vector<edge> edges;
    while (m--) {
      char x;
      int y, z;
      cin >> x >> y >> z;
      edges.push_back({y, z, (int) x == 'R'});
    }
    sort(edges.begin(), edges.end(), [&](const edge &a, const edge &b) { return a.cost < b.cost; });
    vector<int> p(n + 1);
    function<int(int)> get = [&](int x) { return x == p[x] ? x : p[x] = get(p[x]); };
    auto Kruskal = [&]() {
      int cost = 0;
      iota(p.begin(), p.end(), 0);
      for (const edge &e : edges) {
        int X = get(e.from);
        int Y = get(e.to);
        if (X != Y) {
          p[Y] = X;
          cost += e.cost;
        }
      }
      return cost;
    };
    int mn = Kruskal();
    reverse(edges.begin(), edges.end());
    int mx = Kruskal();
    k = n - 1 - k;
    cout << (int) (k >= mn && k <= mx) << '\n';
  }
  return 0;
}