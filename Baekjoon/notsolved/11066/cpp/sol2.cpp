#include <iostream>

using namespace std;

const int N = 501;
const int inf = (int) 2e9;

int ac[N], dp[N][N];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
      cin >> dp[i][i];
      ac[i] = ac[i - 1] + dp[i][i];
    }
    for (int s = 2; s <= n; s++) {
      for (int i = 1, e = i + s - 1; e <= n; i++, e++) {
        int mn = inf;
        for (int j = i; j < e; j++) {
          mn = min(mn, dp[i][j] + dp[j + 1][e]);
        }
        dp[i][e] = mn + ac[e] - ac[i - 1];
      }
    }
    int ans = dp[1][n] - ac[n];
    cout << ans << '\n';
  }
//cerr << (float)clock()/CLOCKS_PER_SEC << " seconds." << '\n';
  return 0;
}