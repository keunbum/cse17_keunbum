#include <iostream>

using namespace std;

#define long long long

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  long x, y;
  cin>> x >> y;            
  long z = 100 * y / x;
  if (z >= 99) { cout << -1 << '\n'; return 0; }
  long ans = ((z + 1) * x - 100 * y + 98 - z) / (99 - z);
  cout << ans << '\n';
  return 0;
}