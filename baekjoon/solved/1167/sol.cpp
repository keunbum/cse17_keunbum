#include <bits/stdc++.h>

using namespace std;

struct Edge {
  int from;
  int to;
  int cost;
};

const int N = (int) 1e5;

int q[N];
int dist[N];
bool was[N];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<vector<int>> g(n);
  vector<Edge> edges;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    x--;
    while (true) {
      int y;
      cin >> y;
      if (y == -1) {
        break;
      }
      y--;
      int z;
      cin >> z;
      int id = (int) edges.size();
      edges.push_back({x, y, z});
      g[x].push_back(id);
    }
  }
  function<pair<int, int>(int v)> RunBfs = [&](int v) {
    int b = 0, e = 0;
    q[e++] = v;
    memset(was, false, sizeof(was));
    dist[v] = 0;
    pair<int, int> res = {-1, 0};
    while (b < e) {
      int from = q[b++];
      was[from] = true;
      if (res.second < dist[from]) {
        res.second = dist[from];
        res.first = from;
      }
      for (int id : g[from]) {
        const Edge& edge = edges[id];
        int to = edge.to;
        if (!was[to]) {
          dist[to] = dist[from] + edge.cost;
          q[e++] = to;
        }
      }
    }
    return res;
  };
  cout << RunBfs(RunBfs(0).first).second << '\n';
  return 0;
}
