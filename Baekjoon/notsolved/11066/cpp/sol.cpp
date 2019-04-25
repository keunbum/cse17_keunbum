#include <iostream>

using namespace std;

const int inf = (int) 2e9;
const int N = 501;

int dp[N][N], a[N], ac[N], c[N][N];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
      cin >> a[i];
      ac[i] = ac[i - 1] + a[i];
      c[i][i] = i;
    }
    for (int i = n - 1; i >= 1; i--) {
      for (int d = 1; i + d <= n; d++) {
        int j = i + d;
        dp[i][j] = inf;
        for (int k = c[i][j - 1]; k <= c[i + 1][j]; k++) {
          int foo = dp[i][k - 1] + dp[k][j] + ac[j] - ac[i - 1];
          if (foo < dp[i][j]) {
            dp[i][j] = foo;
            c[i][j] = k;
          }
        }
      }
    }
    cout << dp[1][n] << '\n';
  }
//cerr << (float)clock()/CLOCKS_PER_SEC << " seconds." << '\n';
  return 0;
}