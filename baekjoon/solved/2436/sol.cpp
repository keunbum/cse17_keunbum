#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int g, l;
  cin >> g >> l;
  int m = l / g;
  int s = (int) sqrt(m);
  int ans = 0;
  for (int i = 1; i <= s; i++) {
    if (m % i) continue;
    if (1 == __gcd(i, m / i)) {
      ans = i;
    }
  }
  cout << ans * g << ' ' << m / ans * g << '\n';
  return 0;
}