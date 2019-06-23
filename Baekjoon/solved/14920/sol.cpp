#include <iostream>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int x;
  cin >> x;
  long long ans = 1;
  while (x > 1) {
    if (x & 1) {
      x = 3 * x + 1;
      ans++;
    }
    while (!(x & 1)) {
      x >>= 1;
      ans++;
    }
  }
  cout << ans << '\n';
  return 0;
}