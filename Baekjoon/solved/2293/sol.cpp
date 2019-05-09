#include <iostream>

using namespace std;

int a[123], dp[12345];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, k;
  cin >> n >> k;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  dp[0] = 1;
  for (int j = 0; j < n; j++) {
    for (int i = a[j]; i <= k; i++) {
      dp[i] += dp[i - a[j]];
    }
  }
  cout << dp[k] << '\n';
  return 0;
}
