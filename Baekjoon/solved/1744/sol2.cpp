#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> a(n);
  vector<int> dp(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  sort(a.begin(), a.end());
  dp[0] = a[0];
  for (int i = 1; i < n; i++) {
    dp[i] = max(dp[i - 1] + a[i], (i > 1 ? dp[i - 2] : 0) + a[i - 1] * a[i]);
  }
  cout << dp[n - 1] << '\n';
  return 0;
}
