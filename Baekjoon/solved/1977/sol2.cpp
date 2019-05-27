#include <iostream>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int m, n;
  cin >> m >> n;
  int ans = 0, mn = n;
  for (int i = 1, ii = 1; ; ii += 2 * i + 1, i++) {
    if (ii > n) break;
    if (ii >= m) {
      mn = min(mn, ii);
      ans += ii;
    }
  }
  if (ans) cout << ans << '\n' << mn;
  else cout << -1;
  return 0;
}