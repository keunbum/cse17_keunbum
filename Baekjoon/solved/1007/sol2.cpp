#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout << fixed << setprecision(17);
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    vector<int> x(n), y(n);
    for (int i = 0; i < n; i++) {
      cin >> x[i] >> y[i];
    }
    long long ans = (long long) 1e18;
    function<void(int, int, long long, long long)> Dfs = [&](int pos, int cnt, long long vx, long long vy) {
      if (pos == n) {
        if (cnt == 0) {
          ans = min(ans, vx * vx + vy * vy);
        }
        return;
      }
      if (cnt > 0) Dfs(pos + 1, cnt - 1, vx + x[pos], vy + y[pos]);
      Dfs(pos + 1, cnt, vx - x[pos], vy - y[pos]);
    };
    Dfs(0, n / 2, 0, 0);
    cout << sqrt(ans) << '\n';
  }
  return 0;
}
