#include <iostream>

using namespace std;

int a[2][123456], dp[3][123456];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    for (int i = 0; i < 2; i++) {
      for (int j = 1; j <= n; j++) {
        cin >> a[i][j];
      }
    }
    for (int i = 1; i <= n; i++) {
      dp[0][i] = max(dp[1][i - 1], dp[2][i - 1]) + a[0][i];
      dp[1][i] = max(dp[0][i - 1], dp[2][i - 1]) + a[1][i];
      dp[2][i] = max(dp[0][i - 1], dp[1][i - 1]);
    }
    cout << max(dp[0][n], dp[1][n]) << '\n';
  }
  return 0;
}