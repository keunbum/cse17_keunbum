#include <iostream>

using namespace std;

int a[101];
long long dp[101][21];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  dp[1][a[1]] = 1;
  for (int i = 2; i < n; i++) {
    for (int j = 0; j <= 20; j++) {
      int t = j + a[i];
      if (t >= 0 && t <= 20) dp[i][j] += dp[i - 1][t];
      t = j - a[i];
      if (t >= 0 && t <= 20) dp[i][j] += dp[i - 1][t];
    }
  }
  cout << dp[n - 1][a[n]] << '\n';
  return 0;
}