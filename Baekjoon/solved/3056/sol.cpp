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
  for (int i = 0; i < n; i++) {
    vector<double> new_dp(1 << n, 0.0);
    for (int s = 0; s < (1 << n); s++) {
      int bit_cnt = __builtin_popcount(s);
      if (bit_cnt == i) {
        for (int j = 0; j < n; j++) {
          if ((s & (1 << j)) == 0) {
            new_dp[s | (1 << j)] = max(new_dp[s | (1 << j)], dp[s] * prob[bit_cnt][j]);
          }
        }
      }
    }
    dp = new_dp;
  }
  double ans = dp[(1 << n) - 1] * 100.0;
  cout << fixed << setprecision(17) << ans << '\n';
  return 0;
}
