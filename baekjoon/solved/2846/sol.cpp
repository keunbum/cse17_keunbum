#include <iostream>

using namespace std;

const int N = 1234;

int a[N], dp[N];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  int ans = 0;
  for (int i = 1; i < n; i++) {
    if (a[i - 1] < a[i]) dp[i] = dp[i - 1] + a[i] - a[i - 1];
    ans = max(ans, dp[i]);
  }
  cout << ans << '\n';
  return 0;
}
