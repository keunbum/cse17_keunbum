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
  for (int i = 0; i < n - 1; i++) {
    int x, y, z;
    cin >> x >> y >> z;
    --x; --y;
    g[x].emplace_back(y, z);
  }
  vector<int> max_leaf(n);
  vector<int> dia(n);
  function<void(int)> Dfs = [&](int v) {
    max_leaf[v] = 0;
    int sz = (int) g[v].size();
    for (int i = 0; i < sz; i++) {
      int u, cost;
      tie(u, cost) = g[v][i];
      Dfs(u);
      max_leaf[v] = max(max_leaf[v], max_leaf[u] + cost);
    }
    dia[v] = max_leaf[v];
    for (int i = 0; i < sz; i++) {
      for (int j = i + 1; j < sz; j++) {
        int x, xc, y, yc;
        tie(x, xc) = g[v][i];
        tie(y, yc) = g[v][j];
        dia[v] = max(dia[v], max_leaf[x] + xc + max_leaf[y] + yc);
      }
    }
  };
  Dfs(0);
  cout << *max_element(dia.begin(), dia.end());
  return 0;
}
