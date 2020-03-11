#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  const int inf = (int) 1e9 + 1; 
  int n, m, k;
  cin >> n >> m >> k;
  vector<vector<int>> c(n + 1, vector<int>(m + 1, 1));
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      c[i][j] = min(c[i - 1][j] + c[i][j - 1], inf);
    }
  }
  if (c[n][m] < k) {
    cout << "-1" << '\n';
    return 0;
  }
  string ans = "";
  int step  = n + m;
  for (int i = 0; i < step; i++) {
    int t = (n - 1 >= 0 && m >= 0) ? c[n - 1][m] : 0;
    if (k <= t) {
      ans += 'a';
      --n;
    } else {
      k -= t;
      ans += 'z';
      --m;
    }
  }
  cout << ans << '\n';
  return 0;
}
