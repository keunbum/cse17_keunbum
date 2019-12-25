#include <bits/stdc++.h>

using namespace std;

const int N = 123;

int a[N][N];
long long dp[N][N];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> a[i][j];
    }
  }
  dp[0][0] = 1L;
  for (int x = 0; x < n; x++) {
    for (int y = 0; y < n; y++) {
      if (a[x][y] == 0) {
        continue;
      }
      if (x + a[x][y] < n) {
        dp[x + a[x][y]][y] += dp[x][y];
      }
      if (y + a[x][y] < n) {
        dp[x][y + a[x][y]] += dp[x][y];
      }
    }
  }  
  cout << dp[n - 1][n - 1] << '\n';
  return 0;
}
