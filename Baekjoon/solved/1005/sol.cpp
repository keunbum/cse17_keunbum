#include <bits/stdc++.h>

using namespace std;

int Dfs(int v, vector<int>& dp, const vector<vector<int>>& g, const vector<int>& cost) {
  if (dp[v] >= 0) {
    return dp[v];
  }
  int mx = 0;
  for (int u : g[v]) {
    mx = max(mx, Dfs(u, dp, g, cost));
  }
  return dp[v] = mx + cost[v];
}

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
    while (k--) {
      int x, y;
      cin >> x >> y;
      --x; --y;
      g[y].push_back(x);
    }
    int w;
    cin >> w;
    --w;
    vector<int> dp(n, -1);
    cout << Dfs(w, dp, g, cost) << '\n';
  }
  return 0;
}
