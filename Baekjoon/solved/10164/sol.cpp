#include <iostream>

using namespace std;

int dp[16][16];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m, k;
  cin >> n >> m >> k;
  dp[1][1] = 1;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      dp[i][j] += dp[i][j - 1] + dp[i - 1][j];
    }
  }
  if (k == 0) { cout << dp[n][m] << '\n'; return 0; }
  --k;
  int x = k / m + 1;
  int y = k % m + 1;
  cout << dp[x][y] * dp[n - x + 1][m - y + 1] << '\n';
  return 0;
}
