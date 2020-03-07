#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<vector<double>> prob(n, vector<double>(n));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> prob[i][j];
      prob[i][j] /= 100.0;
    }
  }
  vector<double> dp(1 << n);
  dp[0] = 1.0;
  for (int i = 0; i < (1 << n) - 1; i++) {
    for (int j = 0; j < n; j++) {
      if ((i & (1 << j)) == 0) {
        dp[i | (1 << j)] = max(dp[i | (1 << j)], dp[i] * prob[__builtin_popcount(i)][j]);
      }
    }
  }
  double ans = dp[(1 << n) - 1] * 100.0;
  cout << fixed << setprecision(17) << ans << '\n';
  return 0;
}
