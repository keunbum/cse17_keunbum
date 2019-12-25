#include <iostream>
#include <cmath>

using namespace std;

int a[1234];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  for (int i = 1; i <= 1000; i++) {
    a[i] = (-1 + sqrt(8 * (i - 1) + 1)) / 2 + 1;
  }
  int m, n;
  cin >> m >> n;
  int ans = 0;
  while (m <= n) ans += a[m++];
  cout << ans << '\n';
  return 0;
}