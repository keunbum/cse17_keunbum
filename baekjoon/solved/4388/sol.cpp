#include <iostream>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  while (true) {
    int x, y;
    cin >> x >> y;
    if (!x && !y) break;
    int ans = 0;
    int p = 0;
    while (x || y) {
      int c = (x % 10 + y % 10 + p) / 10;
      if (c) ans++;
      x /= 10;
      y /= 10;
      p = c;
    }
    cout << ans << '\n';
  }
  return 0;
}	