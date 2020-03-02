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
  const int inf = (int) 2e9;
  int n, m;
  cin >> n >> m;
  vector<vector<int>> g(n);
  vector<Edge> edges;
  while (m--) {
    int x, y, z;
    cin >> x >> y >> z;
    --x; --y;
    int id = (int) edges.size();
    g[x].push_back(id);
    g[y].push_back(id);
    edges.push_back({x, y, z});
  }
  int st, en;
  cin >> st >> en;
  --st; --en;
  vector<int> max_in_mins(n, 0);
  priority_queue<pair<int, int>> s;
  max_in_mins[st] = inf;
  s.emplace(inf, st);
  while (!s.empty()) {
    int expected, v;
    tie(expected, v) = s.top();
    s.pop();
    if (max_in_mins[v] != expected) {
      continue;
    }
    for (int id : g[v]) {
      const auto& e = edges[id];
      int to = v ^ e.from ^ e.to;
      int cur_max = min(max_in_mins[v], e.cost);
      if (cur_max > max_in_mins[to]) {
        max_in_mins[to] = cur_max;
        s.emplace(cur_max, to);
      }
    }
  }
  cout << max_in_mins[en] << '\n';
  return 0;
}
