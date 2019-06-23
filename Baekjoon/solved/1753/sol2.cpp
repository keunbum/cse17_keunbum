#include <bits/stdc++.h>

using namespace std;

const int inf = (int) 1e9;

struct edge {
  int from, to, cost;
  edge(int _f, int _t, int _c) : from(_f), to(_t), cost(_c) {}
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m, st;
  cin >> n >> m >> st;
  st--;
  vector<edge> edges;
  vector<vector<int>> g(n);
  while (m--) {
    int x, y, z;
    cin >> x >> y >> z;
    x--; y--;
    int id = (int) edges.size();
    g[x].push_back(id);
    edges.emplace_back(x, y, z);
  }
  vector<int> ans(n, inf);
  priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> s;
  ans[st] = 0;
  s.emplace(ans[st], st);
  while (!s.empty()) {
    int expected = s.top().first;
    int i = s.top().second;
    s.pop();
    if (ans[i] != expected) continue;
    for (int id : g[i]) {
      auto &e = edges[id];
      int to = e.from ^ e.to ^ i;
      if (ans[i] + e.cost < ans[to]) {
        ans[to] = ans[i] + e.cost;
        s.emplace(ans[to], to);
      }
    }
  }
  for (int x : ans) {
    cout << (x == inf ? "INF" : to_string(x)) << '\n';
  }
  return 0;
}