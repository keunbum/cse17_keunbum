#include <iostream>
#include <vector>
#include <functional>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m, d;
  cin >> n >> m >> d;
  if (m == 0) { cout << 0 << '\n'; return 0; }
  vector<int> p(m);
  for (int i = 0; i < m; i++) {
    cin >> p[i];
    --p[i];
  }
  vector<vector<int>> g(n);
  for (int i = 0; i < n - 1; i++) {
    int x, y;
    cin >> x >> y;
    --x; --y;
    g[x].push_back(y);
    g[y].push_back(x);
  }
  function<void(int, int)> Dfs = [&](int v, int dist) {
    
  };
  Dfs(p[0], 0);
  return 0;
}
