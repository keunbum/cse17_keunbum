#include <iostream>
#include <cassert>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, a, b;
  cin >> n >> a >> b;
  a--;
  b--;
  for (int r = 1; ; r++) {
    if (a >> 1 == b >> 1) { cout << r << '\n'; return 0; }
    a >>= 1;
    b >>= 1;
  }
  assert(1);
  return 0;
}