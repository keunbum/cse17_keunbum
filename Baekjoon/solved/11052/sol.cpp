#include <iostream>

using namespace std;

int dp[123456];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    int x;
    cin >> x;
    for (int j = i; j <= n; j++) {
      dp[j] = max(dp[j], dp[j - i] + x);
    }
  }
  cout << dp[n] << '\n';
//cerr << (float)clock()/CLOCKS_PER_SEC << " seconds." << '\n';
  return 0;
}
