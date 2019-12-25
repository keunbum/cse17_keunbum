#include <iostream>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    long long a, b, c;
    cin >> a >> b >> c;
    long long ans = a * a + b * b + c * c;
    ans += 2 * min(a * b, min(b * c, c * a));
    cout << ans << '\n';
  }
  return 0;
}