#include <iostream>
#include <queue>
#include <vector>
#include <functional>
#include <algorithm>
#include <cassert>

using namespace std;

const int inf = (int) 2e9;

template <typename T>
class graph {
  public:
  struct edge {
    int from;
    int to;
    T cost;
  };
  vector<edge> edges;
  vector<vector<int>> g;
  int n;
  function<bool(int)> ignore;
  graph(int _n) : n(_n) {
    g.resize(n);
    ignore = nullptr;
  }
  virtual int add(int from, int to, T cost) = 0;
  virtual void set_ignore_edge_rule(const function<bool(int)> &f) {
    ignore = f;
  }
  virtual void unset_ignore_edge_rule() {
    ignore = nullptr;
  }
};

template <typename T>
class digraph : public graph<T> {
  public:
  using graph<T>::edges;
  using graph<T>::g;
  using graph<T>::n;
  using graph<T>::ignore;
  digraph(int _n) : graph<T>(_n) {
  }
  int add(int from, int to, T cost = 1) {
    assert(0 <= from && from < n && 0 <= to && to < n);
    int id = (int) edges.size();
    g[from].push_back(id);
    edges.push_back({from, to, cost});
    return id;
  }
};

template <typename T>
vector<T> dijkstra(const graph<T> &g, int start) {
  assert(0 <= start && start < g.n);
  vector<T> dist(g.n, inf);
  priority_queue<pair<T, int>, vector<pair<T, int>>, greater<pair<T, int>>> s;
  dist[start] = 0;
  s.emplace(dist[start], start);
  while (!s.empty()) {
    T expected = s.top().first;
    int i = s.top().second;
    cerr << expected << ' ' << i << '\n';
    s.pop();
    if (dist[i] != expected) {
      continue;
    }
    for (int id : g.g[i]) {
      if (g.ignore != nullptr && g.ignore(id)) {
        continue;
      }
      auto &e = g.edges[id];
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
  int n, m, st;
  cin >> n >> m >> st;
  st--;
  digraph<long long> gd(n);
  while (m--) {
    int x, y, z;
    cin >> x >> y >> z;
    x--; y--;
    gd.add(x, y, z);
  }
  for (auto &e : gd.edges) {
    cerr << e.from << ' ' << e.to << ' ' << e.cost << '\n';
  }

  vector<long long> ans = dijkstra(gd, st);
  for (int x : ans) {
    cout << (x < inf ? to_string(x) : "INF") << '\n';
  }
  return 0;
}