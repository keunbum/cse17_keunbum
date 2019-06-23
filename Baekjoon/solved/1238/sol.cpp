#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct edge {
  int from, to, cost;
  edge(int _from, int _to, int _cost) : from(_from), to(_to), cost(_cost) {}
};

const int inf = (int) 1e9;

int ans1[1234], ans2[1234];
vector<edge> edges;
vector<vector<int>> g;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m, x;
  cin >> n >> m >> x;
  x--;
  g.resize(n);
  fill_n(ans1, n, inf);
  fill_n(ans2, n, inf);
  while (m--) {
    int x, y, z;
    cin >> x >> y >> z;
    x--; y--;
    int id = (int) edges.size();
    g[x].push_back(id);
    g[y].push_back(id);
    edges.emplace_back(x, y, z);
  }
  ans1[x] = 0;
  priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> s;
  s.emplace(ans1[x], x);
  while (!s.empty()) {
    int i = s.top().second;
    s.pop();
    for (int id : g[i]) {
      auto &e = edges[id];
      if (e.from != i) continue;
      if (ans1[i] + e.cost < ans1[e.to]) {
        ans1[e.to] = ans1[i] + e.cost;
        s.emplace(ans1[e.to], e.to);
      }
    }
  }
  ans2[x] = 0;
  s.emplace(ans2[x], x);
  while (!s.empty()) {
    int i = s.top().second;
    s.pop();
    for (int id : g[i]) {              
      auto &e = edges[id];
      if (e.to != i) continue;
      if (ans2[i] + e.cost < ans2[e.from]) {
        ans2[e.from] = ans2[i] + e.cost;
        s.emplace(ans1[e.from], e.from);
      }
    }
  }
  int ans = 0;
  for (int i = 0; i < n; i++) {
    ans = max(ans, ans1[i] + ans2[i]);
  }
  cout << ans << '\n';
  return 0;
}