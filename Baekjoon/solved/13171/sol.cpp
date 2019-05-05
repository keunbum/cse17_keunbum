#include <iostream>

using namespace std;

const int md = (int) 1e9 + 7;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  long long a, x;
  cin >> a >> x;
  a %= md;
  int ans = 1;
  while (x) {
    if (x & 1) {
      ans = (ans * a) % md;
    }
    a = (a * a) % md;
    x >>= 1;
  }
  cout << ans << '\n';
  return 0;
}