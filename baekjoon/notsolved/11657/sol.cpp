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
  const int INF = (int) 1e9;
  int n, m;
  cin >> n >> m;
  vector<Edge> edges;
  while (m--) {
    int x, y, z;
    cin >> x >> y >> z;
    x--; y--;
    edges.push_back({x, y, z});
  }
  vector<int> dist(n, INF);
  dist[0] = 0;
  for (int i = 0; i < n - 1; i++) {
    for (auto& e : edges) {
      if (dist[e.from] < INF) {
        dist[e.to] = min(dist[e.to], dist[e.from] + e.cost);
      }
    }
  }
  bool ok = true;
  for (auto& e : edges) {
    if (dist[e.from] < INF && dist[e.from] + e.cost < dist[e.to]) {
      ok = false;
      break;
    }
  }
  if (!ok) {
    cout << -1 << '\n';
    return 0;
  }
  for (int i = 1; i < n; i++) {
    cout << (dist[i] < INF ? dist[i] : -1) << '\n';
  }
  return 0;
}
