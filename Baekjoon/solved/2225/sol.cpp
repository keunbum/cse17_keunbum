#include <iostream>

using namespace std;

const int md = (int) 1e9;

long long dp[202][202];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, k;
  cin >> n >> k;
  dp[0][0] = 1;
  for (int i = 1; i <= k; i++) {
    for (int j = 0; j <= n; j++) {
      for (int r = 0; r + j <= n; r++) {
        dp[i][j + r] += dp[i - 1][j];
      }
    }
    for (int j = 0; j <= n; j++) dp[i][j] %= md;
  }
  cout << dp[k][n] << '\n';
  return 0;
}
