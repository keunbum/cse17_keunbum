#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int n, k;
    cin >> n >> k;
    vector<int> cost(n);
    for (int i = 0; i < n; i++) {
      cin >> cost[i];
    }
    vector<vector<int>> g(n);
    vector<int> deg(n, 0);
    while (k--) {
      int x, y;
      cin >> x >> y;
      --x; --y;
      g[x].push_back(y);
      ++deg[y];
    }
    vector<int> dp(n, 0);
    vector<int> que;
    for (int v = 0; v < n; v++) {
      if (deg[v] == 0) {
        dp[v] += cost[v];
        que.push_back(v);
      }
    }
    for (int i = 0; i < (int) que.size(); i++) {
      int v = que[i];
      for (int u : g[v]) {
        dp[u] = max(dp[u], dp[v]);
        if (--deg[u] == 0) {
          dp[u] += cost[u];
          que.push_back(u);
        }
      }
    }
    int w;
    cin >> w;
    --w;
    cout << dp[w] << '\n';
  }
  return 0;
}
