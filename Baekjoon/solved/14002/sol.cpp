#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> a(n);
  vector<int> dp(n);
  vector<int> p(n, -1);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    dp[i] = 1;
    for (int j = 0; j < i; j++) {
      if (a[j] < a[i] && dp[i] < dp[j] + 1) {
        dp[i] = dp[j] + 1;
        p[i] = j;
      }
    }
  }
  int x = 0;
  for (int i = 1; i < n; i++) {
    if (dp[i] > dp[x]) {
      x = i;
    }
  }
  cout << dp[x] << '\n';
  vector<int> ans;
  while (x != -1) {
    ans.push_back(a[x]);
    x = p[x];
  }
  reverse(ans.begin(), ans.end());
  for (int i = 0; i < (int) ans.size(); i++) {
    if (i > 0) {
      cout << ' ';
    }
    cout << ans[i];
  }
  cout << '\n';
  return 0;
}
