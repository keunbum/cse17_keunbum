#include <iostream>
#include <algorithm>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int l, n;
    cin >> l >> n;
    int ans1 = 0, ans2 = 0;
    for (int i = 0; i < n; i++) {
      int t;
      cin >> t;
      if (t * 2 >= l) {
        ans1 = max(ans1, l - t);
        ans2 = max(ans2, t);
      } else {
        ans1 = max(ans1, t);
        ans2 = max(ans2, l - t);
      }
    }
    cout << ans1 << ' ' << ans2 << '\n';
  }
  return 0;
}