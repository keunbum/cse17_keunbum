#include <iostream>

using namespace std;

int a[1234], dp[1234];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, ans = 1;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    dp[i] = 1;
    for (int j = 0; j < i; j++) {
      if (a[i] > a[j]) {
        dp[i] = max(dp[i], dp[j] + 1);
      }
      ans = max(ans, dp[i]);
    }
  }
  cout << ans << '\n';
//cerr << (float)clock()/CLOCKS_PER_SEC << " seconds." << '\n';
  return 0;
}