#include <iostream>
#include <vector>
#include <functional>
#include <algorithm>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<vector<pair<int, int>>> g(n);
  for (int i = 0; i < n; i++) {
    int v;
    cin >> v;
    --v;
    int u;
    while (true) {
      cin >> u;
      if (u == -1) {
        break;
      }
      --u;
      int cost;
      cin >> cost;
      g[v].emplace_back(u, cost);
    }
  }
  vector<int> to_leaf(n);
  vector<int> max_len(n);
  function<void(int, int)> Dfs = [&](int v, int p) {
    to_leaf[v] = 0;
    int sz = (int) g[v].size();
    for (int i = 0; i < sz; i++) {
      int u, cost;
      tie(u, cost) = g[v][i];
      if (u == p) {
        continue;
      }
      Dfs(u, v);
      to_leaf[v] = max(to_leaf[v], to_leaf[u] + cost);
    }
    max_len[v] = to_leaf[v];
    for (int i = 0; i < sz; i++) {
      int x, xc;
      tie(x, xc) = g[v][i];
      if (x == p) {
        continue;
      }
      for (int j = i + 1; j < sz; j++) {
        int y, yc;
        tie(y, yc) = g[v][j];
        if (y == p) {
          continue;
        }
        max_len[v] = max(max_len[v], to_leaf[x] + to_leaf[y] + xc + yc);
      }
    }
  };
  Dfs(0, -1);
  cout << *max_element(max_len.begin(), max_len.end()) << '\n';
  return 0;
}