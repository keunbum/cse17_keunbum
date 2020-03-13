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
    vector<int> x(n);
    vector<int> y(n);
    for (int i = 0; i < n; i++) {
      cin >> x[i] >> y[i];
    }
    long long ans = (long long) 1e18;
    for (int bs = 0; bs < (1 << n); bs++) {
      int bit_cnt = __builtin_popcount(bs);
      if (bit_cnt * 2 != n) {
        continue;
      }
      long long vx = 0, vy = 0;
      for (int i = 0; i < n; i++) {
        if (bs & (1 << i)) {
          vx += x[i];
          vy += y[i];
        } else {
          vx -= x[i];
          vy -= y[i];
        }
      }
      ans = min(ans, vx * vx + vy * vy);
    }
    cout << sqrt(ans) << '\n';
//    cerr << (float) clock() / CLOCKS_PER_SEC << " s" << '\n';
  }
  return 0;
}
