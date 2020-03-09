#include <bits/stdc++.h>

using namespace std;

const int md = (int) 1e9 + 7;

inline int Add(int a, int b) {
  a += b;
  if (a >= md) return a - md;
  if (a < 0) return a + md;
  return a;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, k;
  cin >> n >> k;
  if (n * (n - 1) < 2 * k) {
    cout << 0 << '\n';
    return 0;
  }
  vector<int> dp(k + 1, 0);
  for (int step = 1; step <= n; step++) {
    vector<int> new_dp(k + 1, 0);
    new_dp[0] = 1;
    int e = min(step * (step - 1) / 2, k);
    for (int i = 1; i <= e; i++) {
      new_dp[i] = Add(Add(new_dp[i - 1], dp[i]), (i - step < 0 ? 0 : -dp[i - step]));
    }
    dp = new_dp;
  }
  cout << dp[k] << '\n';
//  cerr << (float) clock() / CLOCKS_PER_SEC << " s" << '\n';
  return 0;
}