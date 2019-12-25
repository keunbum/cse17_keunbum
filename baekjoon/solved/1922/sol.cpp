#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

struct edge {
  int from, to, cost;
};

struct St {
  bool operator()(const edge &a, const edge &b) {
    return a.cost > b.cost;
  }
};

priority_queue<edge, vector<edge>, St> edges;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    int x, y, z;
    cin >> x >> y >> z;
    x--; y--;
    edges.push({ x, y, z });
  }
  vector<bool> v(n);
  v[0] = true;
  int cnt = 1;
  int ans = 0;
  while (cnt < n) {
    vector<edge> t;
    while (true) {
      edge e = edges.top();
      edges.pop();
      if (v[e.from] && !v[e.to]) {
        ans += e.cost;
        v[e.to] = true;
        cnt++;
        break;
      }
      if (!v[e.from] && v[e.to]) {
        ans += e.cost;
        v[e.from] = true;
        cnt++;
        break;
      }
      t.push_back(e);
    }
    for (auto &x : t) {
      edges.push(x);
    }
  }
  cout << ans << '\n';
  return 0;
}