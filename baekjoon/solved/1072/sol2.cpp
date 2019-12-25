#include <iostream>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  long x, y;
  cin >> x >> y;
  long q = y * 100 / x;
  if (q >= 99) { cout << -1 << '\n'; return 0; }
  long low = 1, high = (int) 2e9, mid = 0;
  for (int i = 0; i < 100; i++) {
    mid = (low + high) >> 1;
    long z = (y + mid) * 100 / (x + mid);
    if (z > q) high = mid;
    else low = mid + 1;
  }
  cout << mid << '\n';
  return 0;
}