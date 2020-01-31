#include <iostream>
#include <vector>
#include <functional>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, root, tt;
  cin >> n >> root >> tt;
  --root;
  vector<vector<int>> g(n);
  for (int i = 0; i < n - 1; i++) {
    int x, y;
    cin >> x >> y;
    --x; --y;
    g[x].push_back(y);
    g[y].push_back(x);
  }
  vector<int> dp(n);
  vector<bool> was(n, false);
  function<void(int)> Dfs = [&](int v) {
    was[v] = true;
    dp[v] = 1;
    for (int u :g[v]) {
      if (!was[u]) {
        Dfs(u);
        dp[v] += dp[u];
      }
    }
  };
  Dfs(root);
  while (tt--) {
    int v;
    cin >> v;
    --v;
    cout << dp[v] << '\n';
  }
  return 0;
}
