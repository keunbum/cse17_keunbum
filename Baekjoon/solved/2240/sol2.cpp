#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, w;
  cin >> n >> w;
  vector<vector<int>> dp(w + 1, vector<int>(2, 0));
  dp[0][1] = (int) -1e9;
  while (n--) {
    int x;
    cin >> x;
    --x;
    for (int i = 0; i <= w; i++) {
      ++dp[i][x];
      if (i > 0) {
        dp[i][1] = max(dp[i][1], dp[i - 1][0]);
        dp[i][0] = max(dp[i][0], dp[i - 1][1]);
      }
    }
  }
  cout << max(dp[w][0], dp[w][1]) << '\n';
  return 0;
}
