#include <iostream>
#include <vector>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  const int inf = (int) 1e9;
  int n;
  cin >> n;
  vector<int> a(n);
  vector<vector<int>> g(n);
  vector<int> deg(n, 0);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    while (true) {
      int u;
      cin >> u;
      if (u == -1) {
        break;
      }
      --u;
      g[u].push_back(i);
      ++deg[i];
    }
  }
  vector<int> q;
  vector<int> dp(n, -inf);
  for (int i = 0; i < n; i++) {
    if (deg[i] == 0) {
      q.push_back(i);
      dp[i] = a[i];
    }
  }
  for (int ptr = 0; ptr < (int) q.size(); ptr++) {
    int v = q[ptr];
    for (int u : g[v]) {
      dp[u] = max(dp[u], a[u] + dp[v]);
      if (--deg[u] == 0) {
        q.push_back(u);
      }
    }
  }
  for (int i = 0; i < n; i++) {
    cout << dp[i] << '\n';
  }
  return 0;
}
