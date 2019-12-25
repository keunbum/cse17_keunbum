#include <iostream>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int x, y, ans = 0, s = 0;
    cin >> x >> y;
    y -= x;
    while (y > 0) {
      y -= ++s;
      ans++;
      if (y <= 0) break;
      y -= s;
      ans++;
    }
    cout << ans << '\n';
  }
  return 0;
}
