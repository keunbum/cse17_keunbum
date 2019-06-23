#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct edge {
  int from, to;
  long long cost;
  edge(int f, int t, long long c) : from(f), to(t), cost(c) {}
};

const long long inf = (long long) 2e9;

vector<edge> edges;
vector<vector<int>> g;

vector<long long> dijkstra(int start) {
  int n = (int) g.size();
  vector<long long> dist(n, inf);
  dist[start] = 0;
  priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> s;
  s.emplace(dist[start], start);
  while (!s.empty()) {
    int expected = s.top().first;
    int i = s.top().second;
    s.pop();
    if (expected != dist[i]) {
      continue;
    }
    for (int id : g[i]) {
      auto &e = edges[id];
      int to = e.from ^ e.to ^ i;
      if (dist[i] + e.cost < dist[to]) {
        dist[to] = dist[i] + e.cost;
        s.emplace(dist[to], to);
      }
    }
  }
  return dist;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, e;
  cin >> n >> e;
  g.resize(n);
  while (e--) {
    int x, y, z;
    cin >> x >> y >> z;
    x--; y--;
    int id = (int) edges.size();
    g[x].push_back(id);
    g[y].push_back(id);
    edges.emplace_back(x, y, z);
  }
  int u, v;
  cin >> u >> v;
  u--; v--;
  auto dist1 = dijkstra(0);
  auto dist2 = dijkstra(u);
  auto dist3 = dijkstra(n - 1);
  long long ans = min(dist1[u] + dist2[v] + dist3[v], dist1[v] + dist2[v] + dist3[u]);
  cout << (ans < inf ? ans : -1) << '\n';
  return 0;
}