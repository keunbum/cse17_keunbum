#include <iostream>
#include <vector>
#include <queue>
#include <numeric>

using namespace std;

const int inf = (int) 1e9;

struct edge {
  int from, to, cost;
};

vector<edge> edges;
vector<vector<int>> g;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  g.resize(n + 1);
  while (m--) {
    int x, y, z;
    cin >> x >> y >> z;
    int id = (int) edges.size();
    g[x].push_back(id);
    g[y].push_back(id);
    edges.push_back({ x, y, z });
  }
  vector<int> cost(n + 1, inf);
  vector<bool> chk(n + 1, false);
  priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> s;
  cost[1] = 0;
  s.emplace(cost[1], 1);
  int ans = 0;
  while (!s.empty()) {
    int expected = s.top().first;
    int i = s.top().second;
    s.pop();
    if (expected != cost[i]) {
      continue;
    }
    chk[i] = true;
    ans += cost[i];
    for (int id : g[i]) {
      const edge &e = edges[id];
      int to = e.from ^ e.to ^ i;
      if (!chk[to] && e.cost < cost[to]) {
        cost[to] = e.cost;
        s.emplace(cost[to], to);
      }
    }
  }
  cout << ans << '\n';
  return 0;
}