/* 
 *   dp(i, j) : 0 부터 i 번째까지 j 상태로 커버하기 위해 필요한 최소 특수 부대의 수 }
 *
 *         0 1 2 3  <- 4가지의 state로 경우 나누기
 *   0     x o x o
 *   1     x x o o
*/ 

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    const int INF = (int) 2e4;
    int n, w;
    cin >> n >> w;
    vector<vector<int>> a(2, vector<int>(n));
    for (int i = 0; i < 2; i++) for (int j = 0; j < n; j++) cin >> a[i][j];
    if (n == 1) { cout << (a[0][0] + a[1][0] <= w ? 1 : 2) << '\n'; continue; }
    const int A[4][4] = {
      {0, 1, 1, a[0][0] + a[1][0] <= w ? 1 : 2},
      {INF, 0, INF, 1},
      {INF, INF, 0, 1},
      {INF, INF, INF, 0}
    };
    vector<vector<int>> dp(n, vector<int>(4));
    auto Solve = [&](int type) {
      for (int i = 0; i < 4; i++) {
        dp[0][i] = A[type][i];
      }
      for (int i = 1; i < n; i++) {
        // 0
        dp[i][0] = dp[i - 1][3];
        // 1
        dp[i][1] = dp[i][0] + 1;
        if (a[0][i] + a[0][i - 1] <= w) dp[i][1] = min(dp[i][1], dp[i - 1][2] + 1);
        // 2
        dp[i][2] = dp[i][0] + 1;
        if (a[1][i] + a[1][i - 1] <= w) dp[i][2] = min(dp[i][2], dp[i - 1][1] + 1);
        // 3
        dp[i][3] = min(dp[i][1], dp[i][2]) + 1;
        if (a[0][i] + a[1][i] <= w) dp[i][3] = min(dp[i][3], dp[i][0] + 1);
        if (a[0][i] + a[0][i - 1] <= w && a[1][i] + a[1][i - 1] <= w) dp[i][3] = min(dp[i][3], dp[i - 1][0] + 2);
      }
      return dp[n - 1][3 - type];
    };
    int ans = Solve(0);
    bool f1 = a[0][0] + a[0][n - 1] <= w;
    bool f2 = a[1][0] + a[1][n - 1] <= w;
    if (f1) ans = min(ans, Solve(1) + 1);
    if (f2) ans = min(ans, Solve(2) + 1);
    if (f1 && f2) ans = min(ans, Solve(3) + 2);
    cout << ans << '\n';
  }
  return 0;
}
