#include <iostream>
#include <vector>

using namespace std;

struct edge {
  int from, to;
  edge(int _from, int _to) : from(_from), to(_to) {}
};

vector<edge> edges;
vector<vector<int>> g;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  g.resize(n);
  while (m--) {
    int x, y;
    cin >> x >> y;
    x--; y--;
    int id = (int) edges.size();
    g[x].push_back(id);
    edges.emplace_back(x, y);
  }
  vector<int> deg(n, 0);
  for (int id = 0; id < (int) edges.size(); id++) {
    deg[edges[id].to]++;
  }
  vector<int> ans;
  for (int i = 0; i < n; i++) {
    if (deg[i] == 0) {
      ans.push_back(i);
    }
  }
  for (int ptr = 0; ptr < (int) ans.size(); ptr++) {
    int i = ans[ptr];
    for (int id : g[i]) {
      auto &e = edges[id];
      int to = e.to;
      if (--deg[to] == 0) {
        ans.push_back(to);
      }
    }
  }
  for (int x : ans) {
    cout << (x + 1) << ' ';
  }
  cout << '\n';
  return 0;
}