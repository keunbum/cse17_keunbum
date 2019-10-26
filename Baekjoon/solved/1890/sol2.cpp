#include <bits/stdc++.h>

using namespace std;

const int N = 123;

int a[N][N];
long long dp[N][N];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  memset(dp, -1, sizeof(dp));
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> a[i][j];
      if (a[i][j] == 0) {
        dp[i][j] = 0L;
      }
    }
  }
  dp[n - 1][n - 1] = 1L;
  function<long long(int, int)> F = [&](int x, int y) {
    if (~dp[x][y]) {
      return dp[x][y];
    }
    long long res = 0L;
    if (x + a[x][y] < n) {
      res += F(x + a[x][y], y);
    }
    if (y + a[x][y] < n) {
      res += F(x, y + a[x][y]);
    }
    return dp[x][y] = res;
  };
  cout << F(0, 0) << '\n';
  return 0;
}
