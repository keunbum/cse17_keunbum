#include <bits/stdc++.h>

using namespace std;

struct Edge {
  int from;
  int to;
  int cost;
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int n, m, w;
    cin >> n >> m >> w;
    vector<Edge> edges;
    for (int i = 0; i < m + w; i++) {
      int x, y, z;
      cin >> x >> y >> z;
      --x; --y;
      bool digraph = (i < m);
      edges.push_back({x, y, digraph ? z : -z});
      if (digraph) {
        edges.push_back({y, x, z});
      }
    }
    const int inf = (int) 1e9;
    bool neg_cycle = false;
    vector<int> was(n, false);
    for (int v = 0; v < n; v++) {
      if (was[v]) {
        continue;
      }
      was[v] = true;
      vector<int> dist(n, inf);
      dist[v] = 0;
      for (int i = 0; i < n - 1; i++) {
        for (const auto& e : edges) {
          if (dist[e.from] < inf) {
            was[e.to] = true;
            dist[e.to] = min(dist[e.to], dist[e.from] + e.cost);
          }
        }
      }
      for (const auto& e : edges) {
        if (dist[e.from] < inf && dist[e.from] + e.cost < dist[e.to]) {
          neg_cycle = true;
          break;
        }
      }
      if (neg_cycle) {
        break;
      }
    }
    cout << (neg_cycle ? "YES" : "NO") << '\n';
  }
  return 0;
}
