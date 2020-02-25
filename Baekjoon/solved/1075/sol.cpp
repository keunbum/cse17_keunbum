#include <iostream>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, f;
  cin >> n >> f;
  n = n / 100 * 100;
  for (; ; n++) {
    if (n % f == 0) {
      int ans = n % 100;
      if (ans < 10) cout << 0;
      cout << ans << '\n';
      return 0;
    }
  }
  return 0;
}