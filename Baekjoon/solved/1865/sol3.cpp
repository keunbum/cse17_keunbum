#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int n, m, w;
    cin >> n >> m >> w;
    const int inf = (int) 1e9;
    vector<vector<int>> dp(n, vector<int>(n, inf));
    for (int i = 0; i < n; i++) dp[i][i] = 0;
    while (m--) {
      int x, y, z;
      cin >> x >> y >> z;
      --x; --y;
      dp[x][y] = min(dp[x][y], z);
      dp[y][x] = min(dp[y][x], z);
    }
    while (w--) {
      int x, y, z;
      cin >> x >> y >> z;
      --x; --y;
      dp[x][y] = min(dp[x][y], -z);
    }
    bool ok = false;
    for (int k = 0; k < n; k++) {
      for (int i = 0; i < n; i++) {
        if (dp[i][k] == inf) {
          continue;
        }
        for (int j = 0; j < n; j++) {
          dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
        }
      }
      if (dp[k][k] < 0) {
        ok = true;
        break;
      }
    }
    cout << (ok ? "YES" : "NO") << '\n';
  }
  return 0;
}
                                             	