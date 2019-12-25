#include <bits/stdc++.h>

using namespace std;

const int N = 1234;

int a[N], dp[N];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  int ans = 1;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    dp[i] = 1;
    for (int j = 0; j < i; j++) {
      if (a[i] > a[j]) {
        dp[i] = max(dp[i], dp[j] + 1);
      }
    }
    ans = max(ans, dp[i]);
  }
  cout << ans << '\n';
  return 0;
}
