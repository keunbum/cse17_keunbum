#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  const int MAX = (1 << 20) + 1;
  int n, k;
  cin >> n >> k;
  int ans = 0;
  vector<vector<int>> a(n, vector<int>(MAX));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < k; j++) {
      int x;
      cin >> x;
      int p = 1;
      while (a[i][p] != 0) {
        if (x < a[i][p]) {
          p = p + p;
        } else {
          p = p + p + 1;
        }
      }
      a[i][p] = x;
    }
    bool ok = false;
    for (int j = 0; j < i; j++) {
      bool same = true;
      for (int t = 1; t < MAX; t++) {
        if ((a[i][t] > 0 && a[j][t] > 0) || (a[i][t] == 0 && a[j][t] == 0)) {
          continue;
        }
        same = false;
        break;
      }
      ok |= same;
    }
    if (!ok) {
      ans++;
    }
  }
  cout << ans << '\n';
  return 0;
}
